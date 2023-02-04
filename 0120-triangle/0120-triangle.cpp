class Solution {
//     int  minTotal(vector<vector<int>>&triangle,int r,int c, vector<vector<int>> &dp)
//     {
//          int n=triangle.size();
//         if(r==n-1)return triangle[r][c];
        
//         if(dp[r][c]!=-1)
//             return dp[r][c];
//         int down=  triangle[r][c]+minTotal(triangle,r+1,c,dp);
//         int dia=  triangle[r][c]+minTotal(triangle,r+1,c+1,dp);
//         return dp[r][c]=min(down,dia);
//     }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       int n=triangle.size();
       vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int i=0;i<n;i++)
        {
            dp[n-1][i]=triangle[n-1][i];//base case 
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                cout<<i<<" "<<j<<endl;
                int down=  triangle[i][j]+dp[i+1][j];
                int dia=  triangle[i][j]+dp[i+1][j+1]; 
                dp[i][j]=min(down,dia);
            }
        }
      return  dp[0][0];
    }
};