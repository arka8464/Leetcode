class Solution {
    bool isPossible(int mid,vector<int>&nums)
    {
        vector<long long> arr(nums.begin(),nums.end());
        int n=arr.size();
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>mid)
                return false;
            arr[j+1] -= (mid-arr[j]);
        }
            return (arr[n-1]<=mid);

    }
public:
    int minimizeArrayValue(vector<int>& nums) {      
       int low=0,high=1e9;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(isPossible(mid,nums))
                high=mid;
            else 
                low=mid+1;
        }
        return low;
    }
};