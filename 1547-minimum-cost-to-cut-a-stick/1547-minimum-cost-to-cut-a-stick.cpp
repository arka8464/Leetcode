class Solution {
    
    int f(int start,int end,vector<int>& cuts,vector<vector<int>> &dp )
    {
        if(start>end)
            return 0;
        if(dp[start][end]!=-1)
            return dp[start][end];
        int ans=INT_MAX;
        for(int k=start;k<=end;k++)
        {
            int partitionCost=cuts[end+1]- cuts[start-1];
            int leftPartitionCost=f(start,k-1,cuts,dp);
            int rightPartitionCost=f(k+1,end,cuts,dp);
            ans=min(ans,partitionCost+leftPartitionCost+rightPartitionCost);
        }
        return dp[start][end]= ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
         cuts.insert(cuts.begin(), 0);
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        return f(1,m,cuts,dp);
    }
};