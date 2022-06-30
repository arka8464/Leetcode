class Solution {
 public:
  //   int  fib(vector<int>& dp,int n)
  // {
  //     if(n<2)
  //         return dp[n]=n;
  //     if(dp[n]!=-1)
  //         return dp[n];
  //     else return dp[n]=fib(dp,n-1)+fib(dp,n-2);
  // }


    int fib(int n) {
        // vector<int> dp(n+1,-1);
        // dp[n]=fib(dp,n);
        // return dp[n];
         if(n<2)
          return n;
        int prev2=0,prev=1;
        for(int i=2;i<=n;i++)
        {
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
    return prev;
    }
};