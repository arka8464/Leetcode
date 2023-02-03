class Solution {
//     int  minTotal(vector<vector<int>>&triangle,int c,int r, vector<vector<int>> &dp)
//     {
//         if(c<0||r<0)return 1e9;
//         if(c==0&&r==0)return triangle[r][c];
        
//         for(int i=c;i>=0;i--)
//         {
//            int up=triangle[r][i];
//             if()

//         }
        
//     }
public:
    int minimumTotal(vector<vector<int>>& input) {
       int n=input.size();
      vector<vector<int>> dp(n, vector<int>(n, 0));
for (int i = 0; i < n; i++)
{
dp[n - 1][i] = input[n - 1][i];
}
for (int i = n - 2; i >= 0; i--)
{
for (int j = 0; j <= i; j++)
{
int down = dp[i + 1][j];
int diag = dp[i + 1][j + 1];
dp[i][j] = min(down, diag) + input[i][j];
}
}
return dp[0][0];
    }
};