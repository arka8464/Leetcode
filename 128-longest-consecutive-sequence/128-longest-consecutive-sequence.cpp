class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++)
            s.insert(nums[i]);
        
        int ans=0;
        
        for(auto it:s)
        {
            if(s.count(it-1)!=0)
                continue;
            int j=1;
            while(s.count(it+j)!=0)
            {
                j++;
            }
            ans=max(ans,j);
        }
        return ans;
    }
};