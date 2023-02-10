class Solution {
    bool f(vector<int>& a,int n,int k,vector<vector<int>>& dp)
    {
       if(k==0)return true;
        if(n==0)return a[0]==k;
        if( dp[n][k]!=-1)
            return  dp[n][k];
        bool pick=false;
        bool notPick=f(a,n-1,k,dp);
        if(a[n]<=k)
            pick=f(a,n-1,k-a[n],dp);
        
        return dp[n][k]=pick||notPick;
    }
public:
    bool canPartition(vector<int>& nums) {
       
        int sum=0;
        for (int i=0;i<nums.size();i++)sum+=nums[i];

        vector<vector<int>> dp(nums.size(),vector<int>((sum/2)+1,-1));
        if(sum & 1) return false;
         return f(nums,nums.size()-1,sum/2,dp);
    }
};