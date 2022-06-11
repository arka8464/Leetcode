class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int lc=matrix[0].size();
     int rl=matrix.size();
        int r=0,c=lc-1;
        while(r<rl&&c>=0)
        {
            if(target==matrix[r][c])
                return true;
            else if (target<=matrix[r][c])
                c--;
            else
                r++;
        }
        return false;
    }
};
    
/*
//naive approach T.C O(n^2)
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==target)
                    return true;
            }
        }
        return false;
*/