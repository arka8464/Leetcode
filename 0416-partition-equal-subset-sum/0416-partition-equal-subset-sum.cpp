class Solution {
    bool f(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0)
        return true;
    
    if(ind == 0)
        return arr[0] == target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    bool notTaken = f(ind-1,target,arr,dp);
    
    bool taken = false;
    if(arr[ind]<=target)
        taken = f(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken||taken;
}
public:
    bool canPartition(vector<int>& nums) {
       
        int sum=0;
        for (int i=0;i<nums.size();i++)sum+=nums[i];

        vector<vector<int>> dp(nums.size(),vector<int>((sum/2)+1,-1));
        if(sum & 1) return false;
         return f(nums.size()-1,sum/2,nums,dp);
    }
};