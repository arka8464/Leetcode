class Solution {
    void f(string s,vector<string> &ans,string curr,int ind)
    {
        if(ind==s.size())
        {
            ans.push_back(curr);
            curr="";
            return;
        }
        if(s[ind]-'0'>=0&&s[ind]-'0'<=9)
        {
            curr.push_back(s[ind]);
            f(s,ans,curr,ind+1);
        }
        else
        {
           curr.push_back(toupper(s[ind]));
            f(s, ans, curr, ind + 1);
            curr.pop_back();
            
            curr.push_back(tolower(s[ind]));
            f(s, ans, curr, ind + 1);

        }
    }
public:
    vector<string> letterCasePermutation(string s) {
      vector<string> ans;
        
        string curr="";
        
        f(s,ans,curr,0);
       return ans;
    }
};