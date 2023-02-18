class Solution {
    int f(vector<int>& cuts,int i,int j,vector<vector<int>> &dp )
    {
        if(i>j)return 0;
        
        int ans=INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        for(int k=i;k<=j;k++)
        {
            int cost=cuts[j+1]-cuts[i-1]+f(cuts,i,k-1,dp)+f(cuts,k+1,j,dp);
            ans=min(ans,cost);
        }
        return dp[i][j]=ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        
        // for(auto it:cuts)
        //     cout<<it<<" ";
        // cout<<endl<<c<<endl;
        
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        return f(cuts,1,c,dp);
    }
};