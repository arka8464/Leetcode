class Solution {
    int f(vector<int>& coins, int amount,int ind,vector<vector<int>> &dp)
    {
        if(amount<0)
            return 1e8;
        if(ind==0)
        {
            if(amount%coins[0]==0)
                return amount/coins[0];
            return 1e8;
        }
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        int notpick=f(coins,amount,ind-1,dp);
        int pick=1e8;
        if(amount>=coins[ind])
            pick=1+f(coins,amount-coins[ind],ind,dp);
        return dp[ind][amount]=min(pick,notpick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans= f(coins,amount,coins.size()-1,dp);
        if(ans>=1e8)
            return -1;
        return ans;
    }
};