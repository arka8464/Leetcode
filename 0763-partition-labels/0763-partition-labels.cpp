class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>last;
        vector<int>ans;
        
        for(int i=0;i<s.size();i++)
           last[s[i]]=i;                    
        
        
        int min=-1,maxi=0;
        
        for(int i=0;i<s.size();i++)
        {
            maxi=max(maxi,last[s[i]]);
            if(i==maxi)
            {
                ans.push_back(maxi-min);
                min=maxi;
            }
        }
        
        return ans;
    }
};