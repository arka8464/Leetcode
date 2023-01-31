class Solution {
    int uniquePaths(vector<vector<int>>& obstacleGrid,int m, int n,vector<vector<int>>&dp)
    {
        if(n<0||m<0)return 0;
        if(obstacleGrid[m][n]==1)return 0;
        if(n==0&&m==0) 
            return dp[0][0]=1;
        
        
        if(dp[m][n]!=-1)
            return dp[m][n];
        int left=uniquePaths(obstacleGrid,m-1,n,dp);
        int right=uniquePaths(obstacleGrid,m,n-1,dp);
        return dp[m][n]=left+right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
         vector<vector<int>> dp(m,vector<int>(n,-1));
        return uniquePaths(obstacleGrid,m-1, n-1,dp);
    }
};