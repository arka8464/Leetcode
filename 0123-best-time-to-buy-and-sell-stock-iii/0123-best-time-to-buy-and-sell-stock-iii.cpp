class Solution {
    int f(vector<int>& prices,int canBuy,int ind,int sz,int trNo,vector<vector<vector<int>>> &dp)
    {
        //base
        if(trNo==0)
            return 0;
        if(ind==sz)
            return 0;
        
        if(dp[ind][canBuy][trNo]!=-1)
            return dp[ind][canBuy][trNo];
        int profit=0;
        // cout<<ind<<endl;
        if(canBuy==1)
         profit= max (f(prices,1,ind+1,sz,trNo,dp),-prices[ind]+f(prices,0,ind+1,sz,trNo,dp));
        else
         profit =max(f(prices,0,ind+1,sz,trNo,dp),prices[ind]+f(prices,1,ind+1,sz,trNo-1,dp));

        return dp[ind][canBuy][trNo]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(3,-1)));
        return f(prices,1,0,prices.size(),2,dp);   
    }
};