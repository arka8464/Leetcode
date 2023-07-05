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
        
        // return f(obstacleGrid,r-1,c-1,dp);
        
       
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                
                 if(obstacleGrid[i][j]==1)
                {
                    dp[i][j]=0;
                }
                else if(i==0&&j==0)
                {
                 dp[i][j]=1;
                }
                else
                {
                    int up=0,left=0;
                    if(i>0)
                    up=f(obstacleGrid,i-1,j,dp);
                    if(j>0)
                    left=f(obstacleGrid,i,j-1,dp);
                 dp[i][j]=up+left;
                }
            }
        }
        
        return dp[r-1][c-1];
    }
};