class Solution {
public:
    static bool compare(pair<int,int>& a, pair<int,int>&b)
    {
            
        return a.first>=b.first;
       
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        
        for(auto it:nums)
            m[it]++;
        
        vector<pair<int,int>>v;
        
        for(auto it:m)
        {
            cout<<it.first<<" "<<it.second<<endl;
            v.push_back({it.second,it.first});
        }
        cout<<endl;
     
        sort(v.begin(),v.end(),compare);
       
          for(auto it:v)
            cout<<it.first<<" "<<it.second<<endl;
        vector<int>ans;
        for(int i=0;i<k;i++)
            ans.push_back(v[i].second);
        
        return ans;
    }
};