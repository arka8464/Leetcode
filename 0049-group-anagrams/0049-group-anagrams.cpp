class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> ans;
        
        // vector<pair<string,int>> str
        
        
        for(int i=0;i<str.size();i++)
        {
            string t=str[i];
            sort(t.begin(),t.end());
            m[t].push_back(str[i]);
            
        }
        
       for(auto it:m)
       {
           vector<string>temp;
           
           for(auto it1:it.second)
           {
               temp.push_back(it1);
           }
           ans.push_back(temp);
       }
         
        return ans;
    }
};