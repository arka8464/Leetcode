class Solution {
public:
    int solve(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(r==0&&c==0)
            return grid[0][0];
        if(r<0||c<0)
            return 1e9;
        if(dp[r][c]!=-1)
            return dp[r][c];
        int up=grid[r][c]+solve(r-1,c,grid,dp);
        int left=grid[r][c]+solve(r,c-1,grid,dp);
        return dp[r][c]=min(up,left);
    }
        
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dp(r,vector<int>(c,-1));
        return solve(r-1,c-1,grid,dp);
    }
};