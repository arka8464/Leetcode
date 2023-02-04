class Solution {
    int cp(vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,int r,int c1,int c2)
    {
        int n=grid.size();
        int m=grid[0].size();

        if(r>=n||c1<0||c2<0||c2>=m||c1>=m)
            return -1e8;
        if(r==n-1)
        {
            if(c1==c2)
                return grid[r][c1];
           return 
               grid[r][c1]+grid[r][c2];
           
        }
        if(dp[r][c1][c2]!=-1)
            return dp[r][c1][c2];
            
        int ans=-1e8;
        for(int dj1=-1;dj1<=+1;dj1++)
        {
              for(int dj2=-1;dj2<=+1;dj2++)
              {
                  int val=0;
                  if(c1==c2)
                          val=grid[r][c1];
                  else  val=grid[r][c1]+grid[r][c2];
                  val+=cp(grid,dp,r+1,c1+dj1,c2+dj2);
             ans=max(ans,val);       
                           
              }
        }
      return dp[r][c1][c2]=ans;  
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();

        vector<vector<vector<int>>>dp (r,vector<vector<int>>(c,vector<int>(c,-1)));
        return cp(grid,dp,0,0,c-1);
    }
};