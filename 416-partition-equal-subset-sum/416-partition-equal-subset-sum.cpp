class Solution {
    public:
    int dp[201][10001];
     Solution()
          {
           memset(dp,-1,sizeof(dp));   
          }
    bool SubsetSum(vector<int>& arr,int n,int sum)
    {
         if (sum == 0)
        return true;
    if (n == 0)
        return false;
        
          if(dp[n][sum]!=-1)
          return dp[n][sum];
     
       
         if(arr[n-1]<=sum)
         {
             return dp[n][sum]= SubsetSum(arr,n-1,sum-arr[n-1])||SubsetSum(arr,n-1,sum);
         }
         else 
           return dp[n][sum]= SubsetSum(arr,n-1,sum);
    }

    bool canPartition(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++)
            count+=nums[i];
        
        if(count%2!=0)
            return false;
        
        return SubsetSum(nums,nums.size(),count/2); 
        
    }
};