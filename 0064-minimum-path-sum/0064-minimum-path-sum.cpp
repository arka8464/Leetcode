class Solution {
    int minPathSum(vector<vector<int>>& grid,int r,int c, vector<vector<int>>&dp)
    {
        if(r==0&&c==0)return dp[0][0]= grid[0][0];
        if(r<0||c<0)return 1e9;
        if(dp[r][c]!=-1)
            return dp[r][c];
        int up= grid[r][c]+minPathSum(grid,r-1,c,dp);
        int left= grid[r][c]+minPathSum(grid,r,c-1,dp);
        
        return dp[r][c]=min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dp(r,vector<int>(c,-1));
        return minPathSum(grid,r-1,c-1,dp);
    }
};