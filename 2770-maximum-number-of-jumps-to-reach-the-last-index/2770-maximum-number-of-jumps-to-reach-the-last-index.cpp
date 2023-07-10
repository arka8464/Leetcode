class Solution {
    int f(vector<int>& nums, int target,int ind,int tarInd,vector<int>&dp)
    {
   
            
        if(ind==tarInd)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int ans=-1e9;
        for(int i=ind+1;i<nums.size();i++)
        {
            if(abs(nums[ind]-nums[i])<=target)
              ans=max(ans,1+f(nums,target,i,tarInd,dp));
        }
        return dp[ind]=ans;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int>dp(nums.size(),-1);
        int ans=f(nums,target,0,nums.size()-1,dp);
    
    return ans>0?ans:-1;
    }
};