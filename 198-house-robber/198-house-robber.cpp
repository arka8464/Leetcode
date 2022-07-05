class Solution {
    int rob(int ind,vector<int>& dp,vector<int>& house)
    {
      
        
        if(ind==0)
            return house[0];
        
        if(ind<0)
            return 0;
        
           if(dp[ind]!=-1)
            return dp[ind];
        

     
         int pickIndex = house[ind]+ rob(ind-2,dp,house);
           

          int notpickIndex =0+ rob(ind-1,dp,house);

        return dp[ind]=max(pickIndex,notpickIndex);
                
    }
public:
    int rob(vector<int>& house) {
        int n=house.size();
        vector<int> dp(n,-1);
     return rob(n-1,dp,house);
        
    }
};