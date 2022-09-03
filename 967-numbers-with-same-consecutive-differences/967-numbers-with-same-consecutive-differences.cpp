class Solution {
    void dfs(int d,vector<int>& ans,int n,int k)
    {
        if(n==0)
        {
            ans.push_back(d);
            return;
        }
        int last_digit=d%10;
        if(last_digit-k>=0)dfs(d*10+last_digit-k,ans,n-1,k);
        if(k>0)
        if(last_digit+k<10)dfs(d*10+last_digit+k,ans,n-1,k);

            
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        if(n==1)ans.push_back(0);
        for(int d=1;d<10;d++)
              dfs(d,ans,n-1,k);
        return ans;
    }
};