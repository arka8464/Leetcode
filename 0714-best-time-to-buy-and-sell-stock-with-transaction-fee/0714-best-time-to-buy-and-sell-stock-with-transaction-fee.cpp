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
           profit=max(f(prices,fee,ind+1,endInd,true,dp),f(prices,fee,ind+1,endInd,false,dp)- prices[ind]);
        else
           profit=max(f(prices,fee,ind+1,endInd,false,dp),f(prices,fee,ind+1,endInd,true,dp)+prices[ind]-fee);
        
        return dp[ind][canBuy]=profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int  n=prices.size();
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        if(n==0)
            return 0;

        
        int canbuy=true;
        for(int i=n-1;i>=0;i--)
        {
            int profit=0;
            for(int canBuy=0;canBuy<=1;canBuy++)
            {
                if(canBuy==0)// We can buy the stock
                    profit = max(0+dp[i+1][0], -prices[i] + dp[i+1][1]);
            
    
            if(canBuy==1)// We can sell the stock
                profit = max(0+dp[i+1][1], prices[i] -fee + dp[i+1][0]);
            
                
            dp[i][canBuy]  = profit;
            }
        }
        return dp[0][0];
    }
};