class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
    }
};


/*Have some unresolved bug in my code  
vector<pair<int,int>>v;
        pair <int,int>p;
        for(int i=0;i< matrix.size();i++)//this loop is the traverse the matrix and store the location of zero s in a vector of pairs
        {
            for(int j=0;j< matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    v.push_back(make_pair(i,j));
                } 
            }
        }
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                matrix[j][v.at(i).first]=0;
            }
            for(int j=0;j<matrix.size();j++)
            {
                matrix[v.at(i).second][j]=0;
            }
        }
        
*/