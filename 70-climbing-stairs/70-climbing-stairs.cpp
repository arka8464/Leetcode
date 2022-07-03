class Solution {
    int climbStairs(int n,vector<int>& dp) 
    {
        if(n==0||n==1)
            return dp[n]=1;
        if(dp[n]!=-1)
            return dp[n];
        else{
        int left=climbStairs(n-1,dp);
        int right=climbStairs(n-2,dp);
        return dp[n]= left+right;
        }
    }
public:
    
    int climbStairs(int n) 
    {
        vector<int> dp(n+1,-1);
        return  climbStairs(n,dp);
    }
};