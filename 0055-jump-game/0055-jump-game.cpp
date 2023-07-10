class Solution {
    bool f(vector<int>& nums,int ind,int tarInd, vector<int> &dp)
    {
        if(ind==tarInd)
            return true;
        if(ind>tarInd)
            return false;
        
        if(dp[ind]!=-1)
            return dp[ind];
        for(int i=1;i<=nums[ind];i++)
        {
            if(f(nums,ind+i,tarInd,dp))
                return dp[ind] =true;
        }
      return dp[ind] =false;  
    }
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums,0,nums.size()-1,dp);
    }
};