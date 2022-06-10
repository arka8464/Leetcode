class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int sum=0;
        int max_No=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            // max_No=max(max_No,sum);
            if(max_No<sum)
                max_No=sum;
            if(sum<0)
                sum=0;
        }
        return max_No;
    }
};