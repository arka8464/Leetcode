class Solution {
    public:

    int dp[101][101]{};     

    int  up(int tr,int tc,int cr,int cc)
    {
        if(cc>=tc||cr>=tr)
        {
            return 0;
        }
       else if(tc-1==cc&&tr-1==cr)
        {
            return 1 ;
        }
        else if (dp[cr][cc])
            return dp[cr][cc];
        else
          return    dp[cr][cc]=up(tr,tc,cr+1,cc)+up(tr,tc,cr,cc+1); 
        
        
    }
    //   int uniquePaths(int m, int n, int i = 0, int j = 0) {
    //     if(i >= m || j >= n) return 0;
    //     if(i == m-1 && j == n-1) return 1;
    //     if(dp[i][j]) return dp[i][j];
    //     return dp[i][j] = uniquePaths(m, n, i+1, j) + uniquePaths(m, n, i, j+1);
    // }
    int uniquePaths(int m, int n) {
        
        return up(m,n ,0,0);
       
    }
};