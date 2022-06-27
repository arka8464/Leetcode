class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int,vector<int>,greater<int>> h;
        
        for(auto it:nums)
        {
            h.push(it);
            if(h.size()>k)
                h.pop();
        }
        return h.top();
    }
};


/*
Naive approach 
TC :o(nlog(n))  S.C:O(1);
 sort(nums.begin(),nums.end(),greater<int>());
        return nums[k-1];

*/