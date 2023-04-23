class Solution {
public:
    int mod=1e9+7; 
    int solve(int i,int k,vector<int> &num,vector<int> &dp)
    {
        if(i==num.size())return 1;
        if(dp[i]!=-1)return dp[i];
        long long int ans = 0;
        long long int val=0;
        for(int j=i;j<num.size();j++)
        {
            val=val*10+num[j];
            if(val<1 || val>k)break;
            ans+=(solve(j+1,k,num,dp)%mod); 
        }
        return dp[i]=ans%mod;
    }
    int numberOfArrays(string s, int k) {
        vector<int> num;
        for(int i=0;i<s.length();i++)num.push_back(s[i]-'0');
        vector<int> dp(s.length(),-1);
        return solve(0,k,num,dp);
    }
};