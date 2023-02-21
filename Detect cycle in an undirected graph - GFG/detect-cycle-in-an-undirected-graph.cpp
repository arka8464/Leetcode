//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool f(int src, vector<int> adj[],int vis[])
    {
        queue<pair<int,int>> q;
        
        q.push({src,-1});
        vis[src]=1;
        
        while(!q.empty())
        {
           int currNode=q.front().first;
           int parNode=q.front().second;
           q.pop();
           for(auto adjNodes : adj[currNode])
           {
                if(vis[adjNodes]==0)
                  {
                      vis[adjNodes]=1;
                      q.push({adjNodes,currNode});
                  }
                 else if(parNode!=adjNodes)
                      return true;
               
           }
        }
        return 0;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
              if(f(i,adj,vis))return true;  
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends