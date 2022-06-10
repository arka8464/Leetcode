class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int sum=0;
        int max_No=INT_MIN;
        for(auto it:nums)
        {
            sum+=it;
            max_No=max(max_No,sum);
            if(sum<0)
                sum=0;
        }
        return max_No;
    }
};