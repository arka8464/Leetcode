class Solution {
     static bool compare(pair<int,int> p1,pair<int,int> p2)
    {
        if(p1.second<p2.second)
            return true;
        else if(p1.second==p2.second)
        {
           if(p1.first>p2.first)
              return true;
        }
        return false;
        
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>m;
        
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        
        vector<pair<int,int>>v;
        for(auto it:m)
        {
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),compare);
        vector<int>ans;
        for(auto it:v)
        {
            while(it.second--)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
    
};