class Solution {
public:
    // int dp[101][101];
    int cnt(int cr,  int cc,vector<vector<int>> &dp)
    {
         if(cr<0||cc<0)
            return 0;
        
        if(cr==0&&cc==0)
            return 1;
       
        if(dp[cr][cc]!=-1)
            return dp[cr][cc];
        return dp[cr][cc]=cnt( cr-1,  cc,dp)+cnt( cr,  cc-1,dp);
        }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
      return    cnt(m-1,  n-1,dp);
    }
};