class Solution {
    int f(vector<vector<int>>& matrix,vector<vector<int>>& dp,int r,int c)
    {
        
        if(r<0)return +1e8;
        if(c<0||c>=matrix.size())return +1e8;
         if(r==0)return matrix[r][c];
        if(dp[r][c]!=-1)return dp[r][c];
        int up ,upLeft,upRight;
        up =upLeft=upRight=INT_MAX;
        
        up=matrix[r][c]+f(matrix,dp,r-1,c);
         upLeft=matrix[r][c]+f(matrix,dp,r-1,c-1);
         upRight=matrix[r][c]+f(matrix,dp,r-1,c+1);
        // cout<<up<<" "<<upLeft<<" "<<upRight<<endl;
        return dp[r][c]=min(up,min(upLeft,upRight));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
           {
            // cout<<f(matrix,dp,n-1,i)<<endl;
            ans=min(ans,f(matrix,dp,n-1,i)); 
        } 
        return ans;
    }
};