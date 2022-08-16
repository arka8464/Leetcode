class Solution {
    void  combinationSum3(vector<vector<int>>&ans,vector<int>&arr,vector<int>&ds,int index,int k,int target)
    {
        if(ds.size()>k)
            return;
        if(index==arr.size())
        {
            if(target==0&&ds.size()==k)
            {
                ans.push_back(ds);
            }
        return;
        }
        
        if(arr[index]<=target)
        {
        ds.push_back(arr[index]);
        combinationSum3(ans,arr,ds,index+1,k,target-arr[index]);
        ds.pop_back();
        }
         combinationSum3(ans,arr,ds,index+1,k,target);
    }
public:
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int> arr(9);
        vector<vector<int>>ans;
        vector<int>ds;
        for(int i=1;i<=9;i++)
        {
            arr[i-1]=i;
        }
       combinationSum3(ans,arr,ds,0,k,target);
        return ans;
    }
};