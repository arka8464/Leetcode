class Solution {
    void f(vector<string>&ans,int n,int open,int close, string curr)
    {
        //Base case
        if(curr.length()==2*n)
        {
            ans.push_back(curr);
            return ;
        }
        
        if(open<n)
            f(ans,n,open+1,close,curr+'(');
        if(close<open)
            f(ans,n,open,close+1,curr+')');
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        
        string s="";
        f(ans,n,0,0,s);
        
        return ans;
    }
};