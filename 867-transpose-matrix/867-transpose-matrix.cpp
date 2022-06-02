class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        int rl=matrix.size();
        int cl=matrix[0].size();
        
       vector<vector<int>> v(cl,vector<int>(rl,0));
       
        for(int i=0;i<rl;i++)
        {
            for(int j=0;j<cl;j++)
            {
              v[j][i]=matrix[i][j];  
            }
        }
        
        return v;
    }
};