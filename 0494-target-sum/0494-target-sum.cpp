class Solution {

    int f(vector<int>& nums, int target,int ind, vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(target==0&&nums[0]==0)
                return 2;
            if(target==0||nums[0]==target)
                return 1;
            return 0;
        }
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        int pick=0;
        if(nums[ind]<=target)
            pick=f(nums,target-nums[ind],ind-1,dp);
        int notPick=f(nums,target,ind-1,dp);
        
        return dp[ind][target]=pick+notPick;
    }
    public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int totalSum=0;
        for(int i=0;i<nums.size();i++)
        {
            totalSum+=nums[i];
        }
        if(totalSum-target<0||(totalSum-target)%2!=0)
            return 0;
        vector<vector<int>> dp(nums.size()+1,vector<int>(totalSum+1,-1));
        return f(nums,(totalSum-target)/2,nums.size()-1,dp);
    }
};