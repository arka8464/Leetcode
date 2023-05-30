class Solution {
    int f(vector<int>& nums, int k)
    {
       int ans=0;
        for(int i=0;i<nums.size();i++ )
            {
            ans+=(nums[i]/k);
            if(nums[i]%k!=0)
                ans+=1;
        }

        return ans; 
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n=nums.size();
        
        int low=1,high=*max_element(nums.begin(),nums.end());
        
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            cout<<"low "<<low<<"mid "<<mid<<"high "<<high<<endl;
            if(f(nums,mid)<=threshold)
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