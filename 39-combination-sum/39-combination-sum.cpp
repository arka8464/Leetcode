class Solution {
    void combinationSum(vector<int>&candidates,vector<vector<int>>&ans,vector<int>&ds,int ind, int  target)
    {
      if(ind==candidates.size())
      {
         if(target==0)
         {
                                     // cout<<"hello"<<endl;

          ans.push_back(ds);
          }
                    return;

      }
        if(candidates[ind]<=target)
        { 
            ds.push_back(candidates[ind]);

         combinationSum(candidates,ans,ds,ind, target-candidates[ind]);
                        // cout<<"target"<<target<<endl;

         ds.pop_back();
        }
         combinationSum(candidates,ans,ds,ind+1, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          vector<vector<int>> ans;
          vector<int>ds;
          combinationSum(candidates,ans,ds,0, target);
          return ans;
    }
};