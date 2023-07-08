class Solution {
    int f(int amount, vector<int>& coins,int ind, vector<vector<int>> &dp)
    {
        if(ind==0)
            return amount%coins[0]==0;
        // {
        //     if(amount%coins[0]!=0)
        //         return 0;
        //     return amount/coins[0];
        // }
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        int pick=0;
        if(coins[ind]<=amount)
           pick=  f(amount-coins[ind],coins, ind,dp);
        int notPick= f(amount,coins, ind-1,dp);
    
      return dp[ind][amount]=pick+notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
     return f( amount,coins, coins.size()-1,dp);   
    }
};