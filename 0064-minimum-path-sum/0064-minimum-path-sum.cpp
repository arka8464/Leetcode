class Solution {
    int f(vector<vector<int>>& grid,int currR,int currC,vector<vector<int>> &dp)
    {
        if(currR<0||currC<0)
            return 1e9;
        if(currR==0&&currC==0)
            return dp[currR][currC]=grid[0][0];
        if(dp[currR][currC]!=-1)
            return dp[currR][currC];
        // cout<<currR<<" "<<currC<<endl;

        int left= grid[currR][currC]+f(grid,currR,currC-1,dp);
        int up=grid[currR][currC]+ f(grid,currR-1,currC,dp);
        // cout<<left<<" "<<up<<endl;

        return dp[currR][currC]=min(left,up);
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> dp(r+1,vector<int>(c+1,-1));
        
        return f(grid,r-1,c-1,dp);
    }
};