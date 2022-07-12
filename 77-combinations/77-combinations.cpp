class Solution {
    void combine(int ind,int target,vector<vector<int>>&ans,vector<int>&ds,int n)
    {
        if(ds.size()==target)
        {
            ans.push_back(ds);
            return;
        }
        // cout<<ind<<endl;
        for(int i=ind;i<=n;i++)
        {
          ds.push_back(i);
          combine(i+1,target,ans,ds,n);
          ds.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int target) {
        vector<vector<int>> ans;
        vector<int> ds;       
        combine(1,target,ans,ds,n);
        return ans;
    }
};