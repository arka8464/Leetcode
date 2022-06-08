class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        bool iscolzero=false;
        bool isrowzero=false;
        
        for(int i=0;i<m.size();i++)
        {
            if(m[i][0]==0){
               iscolzero=true;
            break;
            }
        }
         for(int i=0;i<m[0].size();i++)
        {
            if(m[0][i]==0){
               isrowzero=true;
            break;
            }
        }
       for(int i=1;i<m.size();i++)
       {
           for(int j=1;j<m[0].size();j++)
           {
                if (m[i][j] == 0) {
                    m[i][0] = 0;
                    m[0][j] = 0;
                }

           }
       }
        for(int i=1;i<m.size();i++)
        {
            for(int j=1;j<m[0].size();j++)
            {
                if(m[0][j]==0||m[i][0]==0)
                    m[i][j]=0;
            }
        }
        
        if(iscolzero)
        {
            for(int i=0;i<m.size();i++)
                m[i][0]=0;
        }
        if(isrowzero)
        {
            for(int i=0;i<m[0].size();i++)
                m[0][i]=0;
        }
    }
};