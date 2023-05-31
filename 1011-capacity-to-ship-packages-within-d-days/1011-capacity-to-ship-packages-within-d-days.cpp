class Solution {
    int f(vector<int>& weights, int days,int wt)
    {
        
        int cnt=1;
        int sum=0;
        
        for(int i=0;i<weights.size();i++)
        {
            if(weights[i]>wt)
                return false;
            
            if(weights[i]+sum>wt)
            {
                sum=weights[i];
                cnt++;
            }
            else
                sum+=weights[i];
        }
        return cnt<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
     
        int lo=*max_element(weights.begin(),weights.end());
        int hi=0;
        for(int i=0;i<weights.size();i++)
            hi+=weights[i];
        
        int ans=-1;
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            
            if(f(weights,days,mid)==true)
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