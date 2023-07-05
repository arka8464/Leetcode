class Solution {
     int f(vector<vector<int>>& obstacleGrid,int currR,int currC,vector<vector<int>>& dp)
     {
         
         if(currR<0||currC<0||obstacleGrid[currR][currC]==1)
             return 0;
         if(currR==0&&currC==0)
             return  dp[currR][currC]=1;
         
         if(dp[currR][currC]!=-1)
             return dp[currR][currC];
         
         int up=f(obstacleGrid,currR-1,currC,dp);
         int left=f(obstacleGrid,currR,currC-1,dp);
         
         return dp[currR][currC]=up+left;
     }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r=obstacleGrid.size();
        int c=obstacleGrid[0].size();
        vector<vector<int>> dp(r+1,vector<int>(c+1,-1));
        
        return f(obstacleGrid,r-1,c-1,dp);
    }
};