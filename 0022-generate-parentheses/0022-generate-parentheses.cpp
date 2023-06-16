class Solution {
    void f(string curr,vector<string>&ans,int n,int cntOpen,int cntClose)
    {
        
        if(curr.size()==2*n)
            {
                    cout<<curr<<endl;

            ans.push_back(curr);
             // curr="";
        }
        if(cntOpen<n)
            {
            f(curr+'(',ans,n,cntOpen+1,cntClose);
        }
        if(cntOpen>cntClose)
        {
             f(curr+')',ans,n, cntOpen,cntClose+1);
        }
        
    }
    public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr="";
        f(curr,ans,n,0,0);//0,0 mane hoche opening bracket er cnt ar closing bracket er cnt
    return ans;
    }
};