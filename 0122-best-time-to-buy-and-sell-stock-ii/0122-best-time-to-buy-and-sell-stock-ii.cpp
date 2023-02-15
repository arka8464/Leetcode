class Solution {
    int f(vector<int>& prices,vector<vector<int>>&dp,int ind,int canBuy,int n)
    {
        //base case
        if(ind==n)return 0;
        if(dp[ind][canBuy]!=-1)
            return dp[ind][canBuy];
        int profit=0;
        if(canBuy==1)
            profit=max(f(prices,dp,ind+1,1,n),-prices[ind]+f(prices,dp,ind+1,0,n));
        else
            profit=max(f(prices,dp,ind+1,0,n),prices[ind]+f(prices,dp,ind+1,1,n));

        return dp[ind][canBuy]=profit;
        
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(prices,dp,0,1,n);
    }
};