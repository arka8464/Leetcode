class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();

        vector<vector<int>> dis(r,vector<int>(c,1e9));
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;
        
        pq.push({{0,0},0});
        dis[0][0]=0;
        
        while(!pq.empty())
        {
            int frntWt=pq.top().second;
            int frntRow=pq.top().first.first;
            int frntCol=pq.top().first.second;

            pq.pop();
            if(frntRow==r-1&&frntCol==c-1)
                return frntWt;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};

            for(int i=0;i<4;i++)
            {
                int adjRow=frntRow+dr[i];
                int adjCol=frntCol+dc[i];

                
                if(adjRow>=0&&adjRow<r&&adjCol>=0&&adjCol<c)
                {
                    int heightDiff=max(frntWt,abs(heights[adjRow][adjCol]-heights[frntRow][frntCol]));
                    if(heightDiff<dis[adjRow][adjCol])
                    {
                        dis[adjRow][adjCol]=heightDiff;
                        pq.push({{adjRow,adjCol},heightDiff});
                    }
                }
            }

        }
        return -1;
        
    }
};