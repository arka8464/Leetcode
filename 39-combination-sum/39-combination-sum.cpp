class Solution {
public:
    void combinationSum(int index, int target,vector<int>& ds,vector<vector<int>>& ans,vector<int>&candidates)
    {
        if(index==candidates.size())
        {
            if(target==0){
            ans.push_back(ds);}   
            return ;
        }
        if(candidates[index]<=target){
        //if picked 
        ds.push_back(candidates[index]);
        combinationSum(index, target-candidates[index],ds,ans,candidates);
        ds.pop_back();
        //if not picked
        }
        combinationSum(index+1, target,ds,ans,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int>ds;
        vector<vector<int>> ans;
        combinationSum(0, target,ds,ans,candidates);
        return ans;
    }
};