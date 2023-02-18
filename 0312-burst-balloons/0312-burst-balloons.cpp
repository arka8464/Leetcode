class Solution {
//     int f(int i,int j,vector<int>& nums, vector<vector<int>>& dp)
//     {
//         if(i>j)return 0;
        
//         int ans=-1e9;
        
//         if(dp[i][j]!=-1)
//             return dp[i][j];
//         for(int k=i;k<=j;k++)
//         {
//             // int cost;
//             // cout<<i<<" "<<j<<" "<<k<<endl;
           
//             int cost =nums[i-1]*nums[k]*nums[j+1]+f(i,k-1,nums,dp)+f(k+1,j,nums,dp);
            
//             ans=max(cost,ans);
//         }
//         return dp[i][j]=ans;
//     }
public:
   int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                
        if(i > j) continue;
        
        int maxi = INT_MIN;
        
        for(int ind = i;ind<=j;ind++){
            
            int cost = nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind-1]
                                                     + dp[ind+1][j];
            
            maxi = max(maxi,cost);
        }
                
           dp[i][j] = maxi;
            }
        }
       return dp[1][n];
    }
};