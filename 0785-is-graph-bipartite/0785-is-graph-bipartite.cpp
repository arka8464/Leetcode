class Solution {
    
    bool dfs(vector<vector<int>>& graph,int start,vector<int> &col,int currCol)
    {
        
       
        col[start]=currCol;
        for(auto adjNodes: graph[start])
        {
            if(col[adjNodes]==-1)
            {  
                   if(dfs(graph,adjNodes,col,!currCol)==false)
                       return false;
            }
            else if(col[adjNodes]==currCol)
                return false;
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
                if (dfs(graph,i,col,0)==false)
                    return false;
            }
        }
        return true;
    }
};