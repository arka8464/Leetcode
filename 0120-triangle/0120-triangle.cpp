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
        int r=triangle.size();
        int c=triangle[r-1].size();
        vector<vector<int>> dp(r+1,vector<int>(c+1,-1));
        return f(triangle,0,0,r,c,dp);
    }
};