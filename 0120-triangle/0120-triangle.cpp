class Solution {
    int  minTotal(vector<vector<int>>&triangle,int r,int c, vector<vector<int>> &dp)
    {
         int n=triangle.size();
        if(r==n-1)return triangle[r][c];
        
        if(dp[r][c]!=-1)
            return dp[r][c];
        int down=  triangle[r][c]+minTotal(triangle,r+1,c,dp);
        int dia=  triangle[r][c]+minTotal(triangle,r+1,c+1,dp);
        
        return dp[r][c]=min(down,dia);
        
       
        
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       int n=triangle.size();
       vector<vector<int>> dp(n,vector<int>(n,-1));
      return  minTotal(triangle,0,0,dp);
    }
};