class Solution {
    long long MOD=1e9+7;
    int f(int ind,int n, int minProfit, vector<int>& group, vector<int>& profit,vector<vector<vector<int>>> &dp)
    {
        
        if(ind<0)// as we have trversed the whole array
        {
            if( minProfit>0)
                return 0;
            return 1;
        }
        // if(ind==0)
        //     return profit[0]>=minProfit&&group[0]>=n;
        if(minProfit<0)
            minProfit=0;
        if(dp[ind][minProfit][n]!=-1)
            return dp[ind][minProfit][n];
        
        int pick=0;
        
         if(n>=group[ind])  
             pick=f(ind-1,n-group[ind],minProfit-profit[ind],group,profit,dp);
        int notPick=f(ind-1,n,minProfit,group,profit,dp);

        return dp[ind][minProfit][n]=(pick+notPick)%MOD;
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
     
       vector<vector<vector<int>>> dp(group.size(),vector<vector<int>> (minProfit+1,vector<int> (n+1,-1)));
        return f(group.size()-1,n,minProfit,group,profit,dp);
    }
};