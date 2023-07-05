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
        vector<vector<int>> dp(r+1,vector<int>(c+1,0));
        
        // return f(grid,r-1,c-1,dp);
        dp[0][0]=grid[0][0];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i==0&&j==0)
                    continue;
               int left=1e9,up=1e9; 
                
                if(i>0)
                   left=grid[i][j]+dp[i-1][j];
                if(j>0)
                   up=grid[i][j]+dp[i][j-1];
                // cout<<"currR"<<i<<"currC"<<j<<"left"<<left<<"right"<<up<<endl;
                dp[i][j]=min(left,up);
            }

        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
               
                cout<<dp[i][j]<<" ";
            }
        cout<<endl;
        }
return dp[r-1][c-1];
    }
};