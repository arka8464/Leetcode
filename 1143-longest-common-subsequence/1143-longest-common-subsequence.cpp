class Solution {
    int f(string &text1, string &text2,int ind1,int ind2,vector<vector<int>> &dp)
    {
        if(ind1<0||ind2<0)
            return 0;
        
        // if(ind1==0&&ind2==0)
        //     return text1[ind1]==text2[ind2];
       

        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        int match=0;
        if(text1[ind1]==text2[ind2])
            match=1+f(text1,text2,ind1-1,ind2-1,dp);
       
        int notMatch=max(f(text1,text2,ind1-1,ind2,dp),f(text1,text2,ind1,ind2-1,dp));
          
        return dp[ind1][ind2]= max(match,notMatch);
        
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        // return f(text1,text2,text1.size()-1,text2.size()-1,dp);
        
        int m=text1.size();
        int n=text2.size();
        for(int i=0;i<=m;i++)
           dp[i][0]=0;

        for(int i=0;i<=n;i++)
            dp[0][i]=0;

        for(int ind1=1;ind1<=m;ind1++)
        {
            for(int ind2=1;ind2<=n;ind2++)
            {
               
            if(text1[ind1-1]==text2[ind2-1])
               dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
           else
            dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
          
  
            }
        }
      return dp[m][n];  
    }
};