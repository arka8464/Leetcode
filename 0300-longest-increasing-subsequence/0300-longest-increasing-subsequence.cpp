class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int curr_ind=nums.size()-1;curr_ind>=0;curr_ind--)
        {
            for(int prev_ind=curr_ind-1;prev_ind>=-1;prev_ind--)
            {
                int take=-1e8;
                int nottake=dp[curr_ind+1][prev_ind+1];
              if(prev_ind==-1||nums[curr_ind]>nums[prev_ind])
                 take=1+dp[curr_ind+1][curr_ind+1];
              
            dp[curr_ind][prev_ind+1]=max(take,nottake);
            }
        }
        
        return dp[0][-1+1];
            
    }
};