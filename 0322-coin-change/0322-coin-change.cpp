class Solution {
    int f(vector<int>& coins,int amount,int ind, vector<vector<int>> &dp)
    {
       //base case
        if(ind==0)
        {
            if(amount%coins[0]==0)
                return amount/coins[0];
            else return 1e8;
        }
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        int pick=1e8;
        int notPick=f(coins,amount,ind-1,dp);
        
        if(coins[ind]<=amount)
            pick=f(coins,amount-coins[ind],ind,dp)+1;
       return dp[ind][amount]=min(pick,notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
         int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        
        int ans=f(coins,amount,n-1,dp);
        if(ans>=1e8)
            return -1;
        return ans;
    }
};