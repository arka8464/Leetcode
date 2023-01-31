class Solution {
    int robme(vector<int>& house) {
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
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
       vector<int>temp1;
               vector<int>temp2;
 for(int i=0;i<nums.size();i++)
 {
     if(i!=0)temp1.push_back(nums[i]);
     if(i!=nums.size()-1)temp2.push_back(nums[i]);

 }
        return max(robme(temp1),robme(temp2));
    }
};