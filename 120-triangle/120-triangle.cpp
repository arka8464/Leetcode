class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle,vector<vector<int>>& dp,int tr,int i,int j)
    {
       if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(i==tr) 
          return triangle[i][j];
        
        // if(i>tr)
        //     return 0;
        
     
       
        int down=triangle[i][j]+minimumTotal( triangle,dp,tr,i+1,j);
        int down_left=triangle[i][j]+minimumTotal( triangle,dp,tr,i+1,j+1);
        
        return dp[i][j]=min(down,down_left);
      
        

    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
       vector<vector<int> > dp(n,vector<int>(n,-1));
       return minimumTotal( triangle,dp,n-1,0,0);
    }
};