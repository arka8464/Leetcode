class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>m;
        
        int currSum=0;
        int ans=0;
        m.insert({0,-1});//eta add korte hobe [0,1]  ei case tr jonyo
        for(int i=0;i<nums.size();i++)
        {
            currSum+=nums[i]==1?1:-1;
            auto it=m.find(currSum);
            if(it!=m.end())
            {
                // cout<<i-m[currSum]+1<<endl;
                ans=max(ans,i-it->second);
            }
            // cout<<"currSum    "<<currSum<<"i    "<<i<<endl;
            else
            m[currSum]=i;
        }
        
        return ans;
    }
};