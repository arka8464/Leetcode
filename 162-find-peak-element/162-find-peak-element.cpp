class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int si=0,ei=nums.size()-1;
        
        while(si<ei)
        {
            int mid=si+((ei-si)/2);
            int nxt=mid+1;
            if(nums[mid]>nums[nxt])
               ei=mid;
            else
                si=mid+1;
        }
        return si;
    }
};