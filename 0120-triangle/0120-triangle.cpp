class Solution {
    int f(vector<vector<int>>& triangle,int currR,int currC,int R,int C,vector<vector<int>>& dp)
     {
        if(currR>=R||currC>=C)
         {
             // cout<<" currR "<<currR<<" currC "<<currC<<endl;
            return 1e9;
         }
        if(currR==R-1)
            return dp[currR][currC]=triangle[currR][currC];
        if(dp[currR][currC]!=-1)
            return dp[currR][currC];
        int down=triangle[currR][currC] + f(triangle,currR+1,currC,R,C,dp);
        int downRight=triangle[currR][currC] + f(triangle,currR+1,currC+1,R,C,dp);
        // cout<<" down "<<down<<" downRight "<<downRight<<" currR "<<currR<<" currC "<<currC<<endl;

        return dp[currR][currC]= min(down,downRight);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // int c=triangle[r-1].size();
       vector<vector<int> > dp(n,vector<int>(n,0));
    
    for(int j=0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = triangle[i][j]+dp[i+1][j];
            int diagonal = triangle[i][j]+dp[i+1][j+1];
            
            dp[i][j] = min(down, diagonal);
        }
    }
    
    return dp[0][0];
    }
};