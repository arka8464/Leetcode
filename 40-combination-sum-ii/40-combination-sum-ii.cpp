class Solution {
    void  combinationSum2(vector<int>&candidates, vector<vector<int>>&ans,vector<int>&ds, int index,int target)
    {
        
            if(target==0)
            {
                ans.push_back(ds);
                 return;
            }
           
        
        
        for(int i=index;i<candidates.size();i++)
        {
            if(i!=index&&candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target)
               break;
            ds.push_back(candidates[i]);
            combinationSum2(candidates,ans,ds, i+1,target-candidates[i]);
             ds.pop_back();    
            
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        // for(int i=0;i<candidates.size();i++)
        // {
        //     cout<<candidates[i]<<endl;
        // }
        combinationSum2(candidates,ans,ds, 0,target);
        return ans;
    }
};