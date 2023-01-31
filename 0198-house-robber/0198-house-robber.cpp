class Solution {
public:
    int rob(vector<int>& house) {
  vector<int > dp(house.size(),-1);
         dp[0]=house[0];
        
        for(int i=1;i<house.size();i++)
        {
            int take=house[i];
            if(i>1)
                take+= dp[i-2];
            
            int nottake=dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[house.size()-1];
    }
};