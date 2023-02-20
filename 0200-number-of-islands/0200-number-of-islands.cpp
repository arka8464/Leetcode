class Solution {
    void dfs(int i,int j,vector<vector<char>>& grid)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]=='0')
            return;
        grid[i][j]='0';
                    dfs(i-1,j,grid);
                    dfs(i,j-1,grid);
                    dfs(i+1,j,grid);
                    dfs(i,j+1,grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        // vector<vector<int>> vis(r,(vector<int>(c,0)));
        int ans=0;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]=='1')
                {
                      cout<<i<<" "<<j<<endl;

                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};