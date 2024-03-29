class Solution {
    
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size()+1,vector<int>(str2.size()+1,-1));
        
        for(int i=0;i<=str1.size();i++)
            dp[i][0]=0;
        
         for(int i=0;i<=str2.size();i++)
            dp[0][i]=0;
        
        
        for(int i=1;i<=str1.size();i++)
        {
            for(int j=1;j<=str2.size();j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
          for(int i=0;i<=str1.size();i++)
        {
            for(int j=0;j<=str2.size();j++)
            {
                
                cout<<dp[i][j]<<" ";
                
            }
          cout<<endl;}
        cout<<dp[str1.size()][str2.size()]<<endl;
        
        string ans="";
        
        int i=str1.size(),j=str2.size();
        
        while(i>0&&j>0)
        {
           if(str1[i-1]==str2[j-1])
           {
               ans+=str1[i-1];
               i--,j--; 
           }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                ans+=str1[i-1];
                i--;
            }
            else
            {
                 ans+=str2[j-1];
                j--;
            }
        }
        while(i>0)
        {
            ans+=str1[i-1];
            i--;
        }
        while(j>0)
        {
            ans+=str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        // return "g";
    
    }
};