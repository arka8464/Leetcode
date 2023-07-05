class Solution {
    
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                 continue;
                else 
                {
                    int up=0,right=0;
                    if(i>0)
                        up=dp[i-1][j];
                    if(j>0)
                        right=dp[i][j-1];
                    dp[i][j]=up+right;
                }
            }
        }
         for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<dp[i][j]<<" ";
            }
             cout<<endl;
         }
       return dp[m-1][n-1]; 
    }
};