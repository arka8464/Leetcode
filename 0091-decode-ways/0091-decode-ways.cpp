class Solution {
    int f(string s,int ind,vector<int> &dp)
    {
        if(ind==s.size())return 1;
        if(s[ind]=='0')return 0;
            
        if(dp[ind]!=-1)
            return dp[ind];
        int pickOne=f(s,ind+1,dp);
       int pickTwo=0;
       if(ind<s.size()-1&&(s[ind]=='1'||(s[ind]=='2'&&s[ind+1]<'7')))
            pickTwo=f(s,ind+2,dp);
        
        return dp[ind]=pickOne+pickTwo;
            
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return f(s,0,dp);
    }
};