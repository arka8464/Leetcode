//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(auto it1:edges)
        {
           
                adj[it1[0]].push_back({it1[1],it1[2]});
                adj[it1[1]].push_back({it1[0],it1[2]});
            
        }
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dis(n+1,1e9);
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++)
          parent[i]=i;
        dis[1]=0;
        pq.push({1,0});
       
        
        while(!pq.empty())
        {
            auto topNode= pq.top().first;
            auto topWt= pq.top().second;
            pq.pop();
            for(auto it : adj[topNode])
            {
                auto adjNode=it.first;
                auto adjDis=it.second;
                
                if(adjDis+topWt<dis[adjNode])
                 {
                     dis[adjNode]=adjDis+topWt;
                     pq.push({adjNode,adjDis+topWt});
                     parent[adjNode]=topNode;
                 }
                
            }
        }
        if(dis[n]==1e9)
        return {-1};
        vector<int>path;
        int node=n;
        while(parent[node]!=node)
        {
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends