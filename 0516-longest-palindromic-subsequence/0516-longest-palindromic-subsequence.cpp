class Solution {
    int f(string &s1,string &s2,int ind1,int ind2,vector<vector<int>> &dp)
    {
        if(ind1<0||ind2<0)
            return 0;
        
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        int match=-1e9;
        if(s1[ind1]==s2[ind2])
           match=1+f(s1,s2,ind1-1,ind2-1,dp);
        
       int notMatch=max(f(s1,s2,ind1-1,ind2,dp),f(s1,s2,ind1,ind2-1,dp));
       return dp[ind1][ind2]=max(match,notMatch);
    }
public:
    int longestPalindromeSubseq(string s2) {
        string s1=s2;
        reverse(s2.begin(),s2.end());
        
        // cout<<s1<<" "<<s2;
        vector<vector<int>> dp(s1.size()+1,vector<int>(s1.size()+1,-1));
        // return f(s1,s2,s1.size()-1,s2.size()-1,dp);
        for(int i=0;i<=s1.size();i++)
            dp[i][0]=0;
         for(int i=0;i<=s1.size();i++)
            dp[0][i]=0;
        
        
        for(int i=1;i<=s1.size();i++)
         {
              for(int j=1;j<=s1.size();j++)
              {
                 int match=-1e9, notMatch=-1e9;
                 if(s1[i-1]==s2[j-1])
                   dp[i][j]=1+dp[i-1][j-1];
                 else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                // dp[i][j]=max(match,notMatch); 
              }
         }
        
         // for(int i=0;i<=s1.size();i++)
         // {
         //      for(int j=0;j<=s1.size();j++)
         //          cout<<dp[i][j]<<" ";
         //     cout<<endl;
         // }
        return dp[s1.size()][s1.size()];
        }
};