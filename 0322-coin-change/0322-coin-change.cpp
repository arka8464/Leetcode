class Solution {
    int f(vector<int>& coins, int ind,int amount,vector<vector<int>> &dp)
    {
        if(ind>=coins.size()||amount<0)
            return 1e9;
        if(ind==coins.size()-1)
        {
            if(amount%coins[ind]==0)
                return dp[ind][amount]=amount/coins[ind];
            return dp[ind][amount]=1e9;
        }
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        int notPick=f(coins,ind+1,amount,dp);
        int pick=1e9;
        
        if(coins[ind]<=amount)
            pick=1+f(coins,ind,amount-coins[ind],dp);
        
        return dp[ind][amount]=min(pick,notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        
                int ans= f(coins,0,amount,dp);

        if(ans==1e9)
            return -1;
        return ans;
    }
};