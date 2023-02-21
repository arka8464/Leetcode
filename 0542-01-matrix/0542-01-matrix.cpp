class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int r=mat.size();
        int c=mat[0].size();
        
        vector<vector<int>> vis(r,vector<int>(c,0)); 
        vector<vector<int>> dis(r,vector<int>(c,0));//creating a new vector for answer 
        
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(mat[i][j]==0)
                    {q.push({{i,j},0}); 
                      vis[i][j]=1;}//taking into the queue all the indexes of the cells which have 0     
                else
                    vis[i][j]=0;
            }
        }
        
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dis[row][col]=steps;
            
            for(int i = 0;i<4;i++) {
	            int nrow = row + delRow[i]; 
	            int ncol = col + delCol[i]; 
	            // check for valid unvisited cell
	            if(nrow >= 0 && nrow < r && ncol >= 0 && ncol < c 
	            && vis[nrow][ncol] == 0) {
	                vis[nrow][ncol] = 1; 
	                q.push({{nrow, ncol}, steps+1});  
	            }
	        }
        }
               return dis;
    }
};