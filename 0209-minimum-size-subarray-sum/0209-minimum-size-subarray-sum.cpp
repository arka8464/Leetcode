class Solution {
    bool f(int target,vector<int>& nums,int mid)
    {
        
        int sum=0;

        for(int i=0;i<mid;i++)
            sum+=nums[i];
        
        int r=mid-1;
        int maxi=sum;
        int l=0;
        while(r!=nums.size()-1)
        {
            sum-=nums[l];
            l++;
            
            
            r++;
            sum+=nums[r];
            maxi=max(maxi,sum);
            
            // cout<<l<<" "<<r<<endl;
        }
        // cout<<( maxi>=target) <<endl;
        return maxi>=target ; 
    }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        
        int lo=1,hi=n;
        int ans=0;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            cout<<lo<<"lo "<<mid<<"mid"<<hi<<" hi"<<endl;
            if(f(target,nums,mid)==true)
            {
                ans=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;          
        }
        
      
        return ans;
        
    }
};