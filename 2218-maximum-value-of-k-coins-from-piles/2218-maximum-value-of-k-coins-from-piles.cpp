class Solution {
    int f(int ind,vector<vector<int>>&piles,int k,vector<vector<int>>&dp)
    {
        // if(dp[i])
        if(k<=0||ind>= piles.size())
            return 0;
        if(dp[ind][k]!=-1)
            return dp[ind][k];
        
        int notPick=f(ind+1,piles,k,dp);
        int pick=0;
        // int currSum=0;
        for(int i=0;i<piles[ind].size()&&i<k;i++)
         {
            // currSum+=piles[ind][i];
            pick=max(pick,piles[ind][i]+f(ind+1,piles,k-i-1,dp));
        }
            
        return dp[ind][k]=max(pick,notPick);
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        //do prefix sum of all elements so that when we pick the latter element then sum of the lower elements can automatically be calculated 
        for(int i=0;i<piles.size();i++)
            for(int j=1;j<piles[i].size();j++)
                piles[i][j]=piles[i][j-1]+piles[i][j];
 
        for(auto it:piles)
          {
            for(auto it1:it)
                cout<<it1<<" ";
        cout<<endl;
        }
        
         vector<vector<int>> dp(piles.size()+1,vector<int>(k+1,-1));
 return f(0,piles,k,dp);
    }
};