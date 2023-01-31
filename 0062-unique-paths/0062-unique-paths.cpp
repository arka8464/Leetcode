class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                {
                    dp[0][0]=1;
                continue; 
                }
                 int up=0;
          int left = 0;
          
          if(i>0) 
            up = dp[i-1][j];
          if(j>0)
            left = dp[i][j-1];
            
          dp[i][j] = up+left;
            }
        }
        return dp[m-1][n-1];
    }
};
/*
class Solution {
    int uniquePaths(int m, int n,vector<vector<int>>&dp)
    {
         if(n==0&&m==0) 
            return dp[0][0]=1;
        if(n<0||m<0)return 0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        int left=uniquePaths(m-1,n,dp);
        int right=uniquePaths(m,n-1,dp);
        return dp[m][n]=left+right;
    }

public:
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m,vector<int>(n,-1));
     return  uniquePaths( m-1,  n-1,dp);
    }
};
*/