class Solution {
    int f(int ind,vector<int>& cost,vector<int>& dp,int sz)
    {
         if(ind==sz)
            return 0;
        if(ind==sz-1)
            return cost[ind];
        if(dp[ind]!=-1)
            return dp[ind];
        int oneStep=cost[ind]+f(ind+1,cost,dp,sz);
        int twoStep=cost[ind]+f(ind+2,cost,dp,sz);

        return dp[ind]=min(oneStep,twoStep);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(f(0,cost,dp,n),f(1,cost,dp,n));
    }
};