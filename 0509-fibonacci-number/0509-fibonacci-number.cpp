class Solution {
public:
  int fib(vector<int>&dp,int n)
  {
       if(n<2)
           return dp[n]= n;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=fib(dp,n-1)+fib(dp,n-2);
  }
    int fib(int n) {
        vector<int> dp(101,-1);
       return fib(dp,n);
    }
};