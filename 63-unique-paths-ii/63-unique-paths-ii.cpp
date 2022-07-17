// class Solution {
// public:
//     int solve(vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp,int cc,int cr)
//     {
//         if(cc>0&&cr>0&&obstacleGrid[cr][cc]==1)return 0;
        
//          if(cc==0&&cr==0)
//             return 1;
        
//         if(cc<0||cr<0)
//             return 0;
        
//         if(dp[cr][cc]!=-1)
//             return dp[cr][cc];
        
//         int left=solve(obstacleGrid,dp,cc-1,cr);
//         int up=solve(obstacleGrid,dp,cc,cr-1);
        
//         return dp[cr][cc]=left+up;
      
//     }
    
    
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int tr=obstacleGrid.size();
//         int tc=obstacleGrid[0].size();

//         vector<vector<int>>dp(tr,vector<int>(tc,-1));
//         return solve(obstacleGrid,dp,tc-1,tr-1);
//     }
// };
 class Solution {
public:
     int m, n;
vector<vector<int> > dp;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	m = size(obstacleGrid), n = size(obstacleGrid[0]);
	dp.resize(m, vector<int>(n));
	return solve(obstacleGrid, 0, 0);
}
// function to recursively explore all unique paths and store the results once calculated
int solve(vector<vector<int>>& grid, int i, int j) {
	if(i < 0 || j < 0 || i >= m || j >= n) return 0;    // bounds checking
	if(grid[i][j]) return dp[i][j] = 0;                 // obstacle found at current cell
	if(i == m - 1 && j == n - 1) return 1;              // reached bottom-right of grid ? return 1
	if(dp[i][j]) return dp[i][j];                       // if already computed for current cell, just return the stored results
	return dp[i][j] = solve(grid, i + 1, j) + solve(grid, i, j + 1); // recursively explore the two options available with us
}
 };
