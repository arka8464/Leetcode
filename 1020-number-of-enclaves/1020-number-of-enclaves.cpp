class Solution {
    void dfs(int r,int c,vector<vector<int>>& grid)
    {

        if(r<0||r>=grid.size()||c<0||c>=grid[0].size())
            return;
        if(grid[r][c]==0)return;
                cout<<r<<" "<<c<<endl;

        // cout<<r<<" "<<c<<endl;
        grid[r][c]=0;
                                                cout<<"hello4"<<endl;

        dfs(r-1,c,grid);
                                                        cout<<"hello5"<<endl;

        dfs(r,c-1,grid);
                                                        cout<<"hello6"<<endl;

        dfs(r+1,c,grid);
                                                        cout<<"hello7"<<endl;

        dfs(r,c+1,grid);

    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
       int ans=0;
          int rw=grid.size();
        int col=grid[0].size();
       if(rw==1&&col==1)
           return 0;

        for(int i=0;i<rw;i++)
        {
                    cout<<"hello1"<<endl;

            if(grid[i][0]==1)
              dfs(i,0,grid);//first col
        }
        for(int i=0;i<rw;i++)
        {
                                cout<<"hello2"<<endl;

            if(grid[i][col-1]==1)
            dfs(i,col-1,grid);//last col
        }
        for(int i=0;i<col;i++)
        {
                                cout<<"hello3"<<endl;

            if(grid[0][i]==1)
            dfs(0,i,grid);//first row
        }
        for(int i=0;i<col;i++)
        {

            if(grid[rw-1][i]==1)
            dfs(rw-1,i,grid);//last row
        }
        
//          for(int i=0;i<rw;i++)
//         {
//             for(int j=0;j<col;j++ )
//             {
//                 cout<<grid[i][j]<<" ";
                
//             }
//              cout<<endl;
//         } 
        // int ans=0;
         for(int i=0;i<rw;i++)
        {
            for(int j=0;j<col;j++ )
            {
                if(grid[i][j]==1)
                {
                    ans++;
                    // dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};