class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int curr_sum=0,ans=0;
        
        int pf[nums.size()];
        pf[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            pf[i]=pf[i-1]+nums[i];

        for(int i=0;i<nums.size();i++)
        {
            if(pf[i]==k)ans++;
            
            if(m.find(pf[i]-k)!=m.end()) ans+=m[pf[i]-k];
            m[pf[i]]++;
        }
        return ans;
    }
};