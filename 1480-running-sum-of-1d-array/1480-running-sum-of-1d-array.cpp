class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
       vector<int> v;
       
        
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            int temp=v[i-1]+nums[i];
            v.push_back(temp);
        }
 return v;
    }
};