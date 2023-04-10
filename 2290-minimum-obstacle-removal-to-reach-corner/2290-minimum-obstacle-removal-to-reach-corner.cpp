// #define pair <int,int> pii
// #define pair<pair<int,int>> ppii

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
   priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
 //storing wt,{row,col}
        int r=grid.size();
        int c=grid[0].size();
        
        pq.push({0,{0,0}});
        vector<vector<int>> dist(r,vector<int>(c,1e9));
        dist[0][0]=0;
        vector<int> dir={0,1,0,-1,0};
        while(!pq.empty())
        {
            int frntWt=pq.top().first;
            int frntRow=pq.top().second.first;
            int frntCol=pq.top().second.second;
            
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int adjRow = frntRow+dir[i];
                int adjCol = frntCol+dir[i+1];
                if(adjRow<0||adjRow>=r||adjCol<0||adjCol>=c)continue;
                int wt;
                if(grid[adjRow][adjCol]==1)
                {
                    wt=1;
                }
                else
                {
                    wt=0;
                }
                
                if(wt+frntWt<dist[adjRow][adjCol])
                    {
                    dist[adjRow][adjCol]=wt+frntWt;
                    pq.push({wt+frntWt,{adjRow,adjCol}});
                    }
            }
        }
        return dist[r-1][c-1];
    }
};