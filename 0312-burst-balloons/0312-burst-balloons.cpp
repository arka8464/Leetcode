class Solution {
    int f(vector<int>& nums,int start,int last, vector<vector<int>> &dp)
    {
        if(start>last)
            return 0;
      if(dp[start][last]!=-1)
          return dp[start][last];
        int ans=INT_MIN;
        for(int k=start;k<=last;k++)
        {
            int cost=nums[start - 1] * nums[k] * nums[last + 1];
            int leftCost=f(nums,start,k-1,dp);
            int rightCost=f(nums,k+1,last,dp);

            ans=max(ans,cost+leftCost+rightCost);
        }
        
        return dp[start][last]= ans;
        
    }
public:
    int maxCoins(vector<int>& nums) {
       int n=nums.size();
         // sort(nums.begin(),nums.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        nums.insert(nums.begin(),1);
       nums.push_back(1); 
       
        return f(nums,1,n,dp);
    }
};