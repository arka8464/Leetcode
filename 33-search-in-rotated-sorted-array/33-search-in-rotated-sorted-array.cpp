class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        
        while(start<=end)
        {
           int mid =start+(end-start)/2;
            if(nums[mid]==target)return mid;
            if(nums[start]<=nums[mid])
            {
                if(target<nums[mid]&&nums[start]<=target)
                    end=mid-1;
                else
                    start=mid+1;
            }
            else{
                if(target>nums[mid]&&nums[end]>=target)
                    start=mid+1;
                else
                    end=mid-1;
            }
        }
        return -1;
    }
};