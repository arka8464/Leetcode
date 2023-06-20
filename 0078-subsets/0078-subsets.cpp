class Solution {
    void f(vector<int>nums,int ind,vector<vector<int>>&ans,vector<int>&temp)
    {
        if(ind==nums.size())
           {
            ans.push_back(temp);
            return ;
           }
        
        temp.push_back(nums[ind]);//take
        f(nums,ind+1,ans,temp);
        temp.pop_back();//backtrack
         f(nums,ind+1,ans,temp);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
       vector<vector<int>>ans;
        vector<int>temp;
         f(nums,0,ans,temp);
        return ans;
    }
};