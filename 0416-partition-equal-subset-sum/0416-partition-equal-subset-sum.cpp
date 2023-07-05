class Solution {
    bool f(vector<int>& nums,int target,int ind,vector<vector<int>>  &dp)
    {
        if(target < 0) {
    return false;
}
        if(ind==nums.size())
        {
            if(target==0)
               return true;
            
            return false;
        }
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        
        bool pick=f(nums,target-nums[ind],ind+1,dp);
        bool notPick=f(nums,target,ind+1,dp);
        return dp[ind][target]= pick||notPick;
    }
public:
    bool canPartition(vector<int>& nums) {
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        
        vector<vector<int>> dp(nums.size(),vector<int>((sum/2)+1,-1));
        if(sum%2!=0)
            return false;
        return f(nums,sum/2,0,dp);
            
    }
};