class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int result=-1;
        int high =nums.size()-1;
        int low=0;
        while(high >=low)
        {
           int mid = low +(high -low)/2;
            if(nums[mid]==target){
               result =mid;
               high=mid-1;
            }
            else if (target>nums[mid])
                low = mid +1;
            else
               high=mid-1; 
        }
        v.push_back(result);
        int result2=-1;
        int high2 =nums.size()-1;
        int low2=0;
        while(high2 >=low2)
        {
           int mid2 = low2 +(high2 -low2)/2;
            if(nums[mid2]==target){
               result2 =mid2;
                low2=mid2+1;
            }
            else if (target>nums[mid2])
                low2 = mid2 +1;
            else
               high2=mid2-1; 
        }
        v.push_back(result2);
        return v;
    }
};