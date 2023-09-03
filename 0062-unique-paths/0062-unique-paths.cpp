class Solution {
    
    int f( vector<vector<int>> &dp,int cr,int cc)
    {
        if(cr<0||cc<0)
            return 0;
        if(cr==0&&cc==0)
            return 1;
        
        if(dp[cr][cc]!=-1)
            return dp[cr][cc]; 
        return dp[cr][cc]= f(dp,cr-1,cc)+f(dp,cr,cc-1);
    }
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        return f(dp,m-1,n-1);
    }
};