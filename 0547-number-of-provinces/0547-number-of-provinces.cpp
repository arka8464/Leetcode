class Solution {
            void dfs(vector<int>adj[],int start,vector<int> &vis)
            {
                vis[start]=1;
                for(auto it: adj[start])
                {
                    if(vis[it]==0)
                    dfs(adj,it,vis);
                }
            }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int V=isConnected.size();
        vector<int>adj[V];
        
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[i].size();j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[j].push_back(i);
                    adj[i].push_back(j);//coverting the adj matrix to adj vector
                }
            }
        }
        vector<int> vis(V,0);
        int ans=0;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
                   {ans++;
                    dfs(adj,i,vis);
                   }
        }
        return ans;
    }
};