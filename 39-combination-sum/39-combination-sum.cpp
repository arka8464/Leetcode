class Solution {
    void combinationSum(int ind,vector<int>& candidates,vector<vector<int>>&ans, int target,vector<int>& ds)
    {
       if(ind==candidates.size())
       {
           if(target==0)
           {
               ans.push_back(ds);
           }
           return;
       }
        if(candidates[ind]<=target)
        {
            ds.push_back(candidates[ind]);
              combinationSum(ind,candidates,ans,target-candidates[ind],ds);
            ds.pop_back();
        }
            combinationSum(ind+1,candidates,ans,target,ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combinationSum(0,candidates,ans,target,ds);
        return ans;
    }
};