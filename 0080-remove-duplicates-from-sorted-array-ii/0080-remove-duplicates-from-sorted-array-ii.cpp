class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]==nums[i])
           {for(int j=i+2;j<nums.size();)
           {
               if(nums[j]==nums[i])
                 nums.erase(nums.begin()+j);
               else
                   j++;
           }}
        }
        return nums.size();
        
        
    }
};