class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0)
            return " ";
    
        string ans=strs[0];
        
        for(int i=1;i<n;i++)
        {
            int j=0;
            for(;j<strs[i].size();j++)
            {
                if(strs[i][j]!=ans[j])
                {
                    break;
                }
            }
             ans=ans.substr(0,j);
        }
        return ans;
        
       
    }
};