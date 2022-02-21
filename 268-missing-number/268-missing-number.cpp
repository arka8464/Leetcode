class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i)
                return i;
        }
        if(nums.back()!=nums.size())
            return nums.size();
        return -1;
    }
};