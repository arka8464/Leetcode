class Solution {
    int f(int ind,vector<int>& moni,vector<int>& dp)
    {
        if(ind<0)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        int notpick=f(ind-1,moni,dp);
        
        int pick=moni[ind]+f(ind-2,moni,dp);
        
        return dp[ind]=max(notpick,pick);
        
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return f(nums.size()-1,nums,dp);
    }
};