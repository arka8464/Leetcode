// class Solution {
//      void combinationSum2(int ind, vector<int>& candidates, int target,vector<vector<int>>& ans,vector<int>&ds)
//      {
//                   // cout<<"Ass"<<endl;
// // for(auto it:candidates)
// //         {
// //             cout<<it<<" ";
// //         }
        
//              if(target==0)
//              {
//                  ans.push_back(ds);
//                  return ;
//              }
         
//          for(int i=ind;i<candidates.size();i++)
//          {
//              if(i>ind&&candidates[i]==candidates[i-1]) continue;
                
//              if(candidates[i]>target)  return;

//              ds.push_back(candidates[i]);
//               combinationSum2(ind+1, candidates, target-candidates[i],ans,ds);
//               ds.pop_back();
//          }
//      }
// public:
    
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//          vector<vector<int>> ans;
//         vector<int> ds;
//         sort(candidates.begin(),candidates.end());
//         // for(auto it:candidates)
//         // {
//         //     cout<<it<<" ";
//         // }
//         combinationSum2(0, candidates, target,ans,ds);
//         return ans;
//     }
// };
class Solution {
    public: 
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&ds) {
        if(target==0) {
            ans.push_back(ds);
            return;
        }        
        for(int i = ind;i<arr.size();i++) {
            if(i>ind && arr[i]==arr[i-1]) continue; 
            if(arr[i]>target) break; 
            ds.push_back(arr[i]);
            findCombination(i+1, target - arr[i], arr, ans, ds); 
            ds.pop_back(); 
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans; 
        vector<int> ds; 
        findCombination(0, target, candidates, ans, ds); 
        return ans; 
    }
};

