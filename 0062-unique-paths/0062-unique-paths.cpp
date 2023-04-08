class Solution {
    int f(int r, int c,int row,int col,vector<vector<int>> &dp)
    {
        if(r<0||r>=row||c<0||c>=col)
            return 0;
        if(r==0&&c==0)
            return 1;
        if(dp[r][c]!=-1)
            return dp[r][c];
        int up=f(r-1, c,row,col,dp);
        int left=f(r, c-1,row,col,dp);
        
        return dp[r][c]=up+left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        
        return f(m-1,n-1,m,n,dp);
        
    }
};