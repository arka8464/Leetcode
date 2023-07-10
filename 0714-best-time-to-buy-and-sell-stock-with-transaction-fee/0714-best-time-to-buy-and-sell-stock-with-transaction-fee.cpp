class Solution {
    int f(vector<int>& prices, int fee,int ind,int endInd,bool canBuy,  vector<vector<int>> &dp)
    {
        //base case
        if(ind==endInd)
        {
            if(canBuy==false)
                return prices[ind]-fee;
            return 0;
        }
        if(dp[ind][canBuy]!=-1)
            return dp[ind][canBuy];
        int profit=0;
        if(canBuy==true)
           profit=max(f(prices,fee,ind+1,endInd,true,dp),f(prices,fee,ind+1,endInd,false,dp)-prices[ind]);
        else
           profit=max(f(prices,fee,ind+1,endInd,false,dp),f(prices,fee,ind+1,endInd,true,dp)+prices[ind]-fee);
        
        return dp[ind][canBuy]=profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int  n=prices.size();
        vector<vector<int>> dp(prices.size()+1,vector<int>(3,-1));
        return f(prices,fee,0,n-1,true,dp);
    }
};