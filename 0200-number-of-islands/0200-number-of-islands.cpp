class Solution {
    
    void dfs(int i,int j, int r,int c,vector<vector<int>>& vis,vector<vector<char>>& grid)
    {
        if(i<0||i>=r||j<0||j>=c||vis[i][j]==1)
            return ;
        
        vis[i][j]=1;
        if(grid[i][j]=='0')
            return;
        dfs(i+1,j,r,c,vis,grid);
        dfs(i,j+1,r,c,vis,grid);
        dfs(i-1,j,r,c,vis,grid);
        dfs(i,j-1,r,c,vis,grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int V=grid.size();
        int C=grid[0].size();

        int ans=0;
        vector<vector<int>> vis(V,vector<int>(C,0));
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(vis[i][j]!=1&&grid[i][j]=='1')
                {
                    ans++;
                    dfs(i,j,V,C,vis,grid);
                    
//                     for(auto it:vis)
//                     {
//                         for(auto it1:it)
//                         {
//                             cout<<it1<<" ";
//                         }
//                         cout<<endl;

//                     }
//                                                                     cout<<endl;

                }
            }
        }
        return ans;
    }
};