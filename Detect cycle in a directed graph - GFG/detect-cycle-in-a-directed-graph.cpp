//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        int indegree [V]={0};
            for(int i=0;i<V;i++)
            {
                for(auto adjNodes:adj[i])
                   indegree[adjNodes]++;
            }
            queue<int>q;
            
            for(int i=0;i<V;i++){
                if(indegree[i]==0)
                 q.push(i);
            }
            vector<int> topo;
            while(!q.empty()){
                int frnt=q.front();
                q.pop();
                topo.push_back(frnt);
                for( auto it:adj[frnt])
                  {indegree[it]--;
                if(indegree[it]==0)
                  q.push(it);}
            }
            
            return !(topo.size()==V);
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