class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      
        for(int i=0;i<9;i++ )//checking for duplicates in row 
        {
            vector<bool> hash(9,0);
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int num=(int ) (board[i][j]-'0');
                    if(hash[num]>0)
                        return false;
                    hash[num]=1;
                }
            }
        }
        
           for(int i=0;i<9;i++ )//checking for duplicates in column 
        {
            vector<bool> hash(9,0);
            for(int j=0;j<9;j++)
            {
                if(board[j][i]!='.')
                {
                    int num=(int ) (board[j][i]-'0');
                    if(hash[num]>0)
                        return false;
                    hash[num]=1;
                }
            }
        }
        
        
        for(int i=0;i<3;i++)//check for duplicates in the smaller sub matrices
        {
            for(int j=0;j<3;j++)
            {
                vector<bool> hash(9,0);
               for(int row=3*i;row<3*(i+1);row++)
                   {
                     for(int col =3*j;col<3*(j+1);col++)
                     {
                         if(board[row][col]!='.')
                {
                    int num=(int ) (board[row][col]-'0');
                    if(hash[num]>0)
                        return false;
                    hash[num]=1;
                }
                     }
                   }
                   
              
            }
            
           
        }
        return true;
        }
};