class Solution {
    int f(vector<int>& prices, vector<vector<vector<int>>>&dp,int ind,int canBuy,int n,int limit)
    {
        //base case
        if(limit==0)return 0;
        if(ind==n)return 0;
        if(dp[ind][canBuy][limit]!=-1)
             return dp[ind][canBuy][limit];
        int profit=0;
        if(canBuy==1)
            profit=max(f(prices,dp,ind+1,1,n,limit),-prices[ind]+f(prices,dp,ind+1,0,n,limit));
        else
            profit=max(f(prices,dp,ind+1,0,n,limit),prices[ind]+f(prices,dp,ind+1,1,n,limit-1));

        return dp[ind][canBuy][limit]=profit;
        
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(prices,dp,0,1,n,2);
    }
};