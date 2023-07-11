class Solution {
    int f(vector<int>& nums,int ind,int prev,vector<vector<int>> &dp)
    {
        // if(ind==nums.size()-1)
        // {
        //     if(nums[prev+1]<nums[ind])
        //        return 1;
        //     else
        //         return 0;
        // }
        if(ind==nums.size())return 0;
        
        if(dp[ind][prev+1]!=-1)
            return dp[ind][prev+1];
        int pick=0;
        if(prev==-1||nums[ind]>nums[prev])
           pick=   1 +  f(nums,ind+1,ind,dp);
        int notPick=f(nums,ind+1,prev,dp);
        return  dp[ind][prev+1]=max(pick,notPick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return f(nums,0,-1,dp);
    }
};