class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dp(r,vector<int>(c,-1));
       
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i==0&&j==0)
                {
                    dp[0][0]=grid[0][0];
                    continue;
                }
                int up=1e9,left=1e9;
                if(i>0)
                    up= grid[i][j]+dp[i-1][j];
                if(j>0)
                    left= grid[i][j]+dp[i][j-1];
                dp[i][j]=min(up,left);
            }
        }
        return dp[r-1][c-1];
    }
};

/*
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
*/