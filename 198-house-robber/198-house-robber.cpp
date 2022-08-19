class Solution {
    int rob(int n,vector<int>& house,vector<int>& dp)
    {
        if(n==0)
            return dp[n]=house[0];
        if(n<0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int picked=rob(n-2,house,dp)+house[n];
                cout<<"hello"<<endl;

        int notpicked=rob(n-1,house,dp);
        return dp[n] = max(picked,notpicked);
        
    }
public:
    int rob(vector<int>& house) {
       int n=house.size();
        vector<int>dp(n,-1);
       return rob(n-1,house,dp);
        
    }
};