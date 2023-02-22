//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool dfs(vector<int> adj[],int vis[],int pathVis[],int start)
    {
        vis[start]=1;
        pathVis[start]=1;
        
        for(auto adjNodes:adj[start])
        {
            if(vis[adjNodes]==0)
            {
                if(dfs(adj,vis,pathVis,adjNodes)==true)return true;//to visit the nodes
            }
            //if visited in same path 
            else if(vis[adjNodes]==1&&pathVis[adjNodes]==1)
               return true;
        }
        pathVis[start]=0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V]={0};
        int pathVis[V]={0};
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(adj,vis,pathVis,i)==true)
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends