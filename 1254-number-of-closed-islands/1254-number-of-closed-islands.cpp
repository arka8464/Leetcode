class Solution {
    void dfs(int r,int c,vector<vector<int>>& grid)
    {
        int rw=grid.size();
        int col=grid[0].size();
        
        if(r<0||r>=rw||c<0||c>=col||grid[r][c]==1)return;
        grid[r][c]=1;
        dfs(r-1,c,grid);
        dfs(r,c-1,grid);
        dfs(r+1,c,grid);
        dfs(r,c+1,grid);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
          int rw=grid.size();
        int col=grid[0].size();
if(rw==1&&col==1)
{
    return 0;
}
        for(int i=0;i<rw;i++)
        {
            if(grid[i][0]==0)
              dfs(i,0,grid);//first col
        }
        for(int i=0;i<rw;i++)
        {
            if(grid[i][col-1]==0)
            dfs(i,col-1,grid);//last col
        }
        for(int i=0;i<col;i++)
        {
            if(grid[0][i]==0)
            dfs(0,i,grid);//first row
        }
        for(int i=0;i<col;i++)
        {
            if(grid[rw-1][i]==0)
            dfs(rw-1,i,grid);//last row
        }
        
         for(int i=0;i<rw;i++)
        {
            for(int j=0;j<col;j++ )
            {
                cout<<grid[i][j]<<" ";
                
            }
             cout<<endl;
        }
        for(int i=0;i<rw;i++)
        {
            for(int j=0;j<col;j++ )
            {
                if(grid[i][j]==0)
                {
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};