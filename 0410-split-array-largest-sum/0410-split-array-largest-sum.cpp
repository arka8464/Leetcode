class Solution {
    bool f(vector<int>& nums,int target,int k)
    {
        int cnt=1;
        
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>target)
                return false;
            
            if(sum+nums[i]>target)
            {
                cnt++;
                sum=nums[i];//if adding it to the sum excedded limit we set that element == sum so that it starts from there ar ager element gulo r value bhulle jai
            }
            else
                sum+=nums[i];
        }
            return cnt<=k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(int i=0;i<nums.size();i++)
            high+=nums[i];
        
        int ans=high;
        while(low<=high)
        {
            int mid=(low+high)/2;

            if(f(nums,mid,k)==true)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        
        return ans;
    }
};