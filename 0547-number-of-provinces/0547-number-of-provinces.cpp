class Solution {
private :
    void dfs(vector<int> &vis,vector<int> adjL[],int start)
    {
        vis[start]=1;
        
        for(auto it:adjL[start])
        {
            if(vis[it]==0)
            {
                dfs(vis,adjL,it);
            }
        }
    }
    public:
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected[0].size();
        vector<int>adjL[V];
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(isConnected[i][j]==1)
                {
                  adjL[i].push_back(j);
                  adjL[j].push_back(i);
                }
            }
        }
         for(int i=0;i<V;i++)
        {
           // cout<<adjL[i][0]<<" ";
          for(int j=0;j<adjL[i].size();j++)
            {
          cout<<adjL[i][j]<<" ";
        }
             cout<<endl;
        }
        
        vector<int>vis(V,0);
        int ans=0;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0){
                                                ans++;

                dfs(vis,adjL,i);

            }
        }
        return ans;
    }
};