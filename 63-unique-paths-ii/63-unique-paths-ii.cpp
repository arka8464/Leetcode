class Solution {
    int cntPaths(int cr,int cc,vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid)
    {
         if(cr<0||cc<0)
            return 0;
        
        if(obstacleGrid[cr][cc]==1)
            return 0;
        
       
        
        if(cr==0&&cc==0)
            return 1;
        
        if(dp[cr][cc]!=-1)
            return dp[cr][cc];
        
    return dp[cr][cc]=cntPaths(cr-1,cc,dp,obstacleGrid)+cntPaths(cr,cc-1,dp,obstacleGrid);
        
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int column=obstacleGrid[0].size();
        vector<vector<int>> dp(row,vector<int>(column,-1));
        return cntPaths(row-1,column-1,dp,obstacleGrid);
    }
};