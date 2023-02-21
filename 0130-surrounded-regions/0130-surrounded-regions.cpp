class Solution {
    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>> &vis)
    {
        if(row<0||col<0||col>=board[0].size()||row>=board.size()||board[row][col]=='X'||vis[row][col]==2)
            return ;
        cout<<row<<" "<<col<<endl;
        vis[row][col]=2;
        dfs(row+1,col,board,vis);
        dfs(row,col+1,board,vis);
        dfs(row-1,col,board,vis);
        dfs(row,col-1,board,vis);

    }
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();

         vector<vector<int>> vis(r,vector<int>(c,0));
        
        for(int i=0;i<c;i++)
        {
            // cout<<"a"<<endl;
            if(board[0][i]=='O')
            dfs(0,i,board,vis);//first row
        }
        for(int i=0;i<c;i++)
        {
            // cout<<"b"<<endl;
            if(board[r-1][i]=='O')
            dfs(r-1,i,board,vis);//last row
        }
        for(int i=0;i<r;i++)
        {
            // cout<<"c"<<endl;
            if(board[i][0]=='O')
            dfs(i,0,board,vis);//first col
        }
         for(int i=0;i<r;i++)
        {
             // cout<<"d"<<endl;
             if(board[i][c-1]=='O')
             dfs(i,c-1,board,vis);//last col
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(vis[i][j]!=2)
                    board[i][j]='X';
            }
        }
        // return board;
    }
};