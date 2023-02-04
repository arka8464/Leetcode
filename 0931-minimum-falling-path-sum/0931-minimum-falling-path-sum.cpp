class Solution {

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=INT_MAX;
       
        
        for(int i=0;i<n;i++)
           {
           dp[0][i]=matrix[0][i];
            
           } 
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                 int up ,upLeft,upRight;
        up =upLeft=upRight=INT_MAX;
               up  =matrix[i][j]+dp[i-1][j];
                if(j>0)
                upLeft=matrix[i][j]+dp[i-1][j-1];
                if(j<n-1)
                upRight=matrix[i][j]+dp[i-1][j+1];
                // cout<<up<<" "<<upLeft<<" "<<upRight<<endl;
                dp[i][j]=min(up,min(upLeft,upRight));
            }
        }
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<dp[i][j]<<" ";
            }
         cout<<endl;
         }
        for(int i=0;i<n;i++)
            ans=min(ans,dp[n-1][i]);
        return ans;
    }
};