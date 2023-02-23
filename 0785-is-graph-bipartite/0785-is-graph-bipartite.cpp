class Solution {
    
    bool bfs(vector<vector<int>>& graph,int start,vector<int> &col)
    {
       
        queue<int> q;
        
        q.push(start);
        
        // bool col=false;
        col[start]=0;
        while(!q.empty())
        {
            int frnt = q.front();
            q.pop();
             
            for(auto adjNodes: graph[frnt])
            {
                cout<<!col[frnt]<<" "<<frnt<<endl;
                if(col[adjNodes]==-1)//not colored at all
                  {
                    col[adjNodes] = !col[frnt];
                    q.push(adjNodes);      
                }
                else if(col[adjNodes] == col[frnt])
                    return false;
                
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int r = graph.size();
        int c =graph[0].size();
        
        vector<int> col(r,-1); //used to store  0 or 1 
        
        for(int i=0;i<r;i++)
        {
            if(col[i]==-1)
            {
                if (bfs(graph,i,col)==false)
                    return false;
            }
        }
        return true;
    }
};