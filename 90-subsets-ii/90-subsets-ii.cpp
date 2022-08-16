class Solution {
    void subsetsWithDup(vector<int>&nums,vector<vector<int>> &ans,vector<int>& ds,int ind)
    {
        // if(ind==nums.size())
            ans.push_back(ds);
        for(int i=ind;i<nums.size();i++)
        {
            if(i!=ind&&nums[i]==nums[i-1])
                continue;
            ds.push_back(nums[i]);
            subsetsWithDup(nums,ans,ds,i+1);
            ds.pop_back();

        }
    }
public:
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
         subsetsWithDup(nums,ans,ds,0);
        return ans;
    }
};