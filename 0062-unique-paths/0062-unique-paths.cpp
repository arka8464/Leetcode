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