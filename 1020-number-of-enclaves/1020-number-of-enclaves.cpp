class Solution {
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        if(row<0||col<0||row>=grid.size()||col>=grid[0].size()||grid[row][col]==0||vis[row][col]==2)
            return ;
        vis[row][col]=2;
        dfs(row-1,col,grid,vis);
        dfs(row,col-1,grid,vis);
        dfs(row,col+1,grid,vis);
        dfs(row+1,col,grid,vis);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> vis(r,vector<int>(c,0));
        
        for(int i=0;i<c;i++)
        {
            // cout<<"a"<<endl;
            if(grid[0][i]==1)
            dfs(0,i,grid,vis);//first row
        }
        for(int i=0;i<c;i++)
        {
            // cout<<"b"<<endl;
            if(grid[r-1][i]==1)
            dfs(r-1,i,grid,vis);//last row
        }
        for(int i=0;i<r;i++)
        {
            // cout<<"c"<<endl;
            if(grid[i][0]==1)
            dfs(i,0,grid,vis);//first col
        }
         for(int i=0;i<r;i++)
        {
             // cout<<"d"<<endl;
             if(grid[i][c-1]==1)
             dfs(i,c-1,grid,vis);//last col
        }
        
        int ans=0;
         for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
               cout<<vis[i][j]<<" ";
            }
             cout<<endl;
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(vis[i][j]!=2&&grid[i][j]==1)
                    { ans++;}
            }
        }
        return ans;
    }
};