class Solution {
    int f(string& s1, string& s2,vector<vector<int>>&dp,int l1,int l2)
    {
        if(l1<0||l2<0)
            return 0;
        if(dp[l1][l2]!=-1)
            return dp[l1][l2];
        if(s1[l1]==s2[l2])
            return 1+ f(s1,s2,dp,l1-1,l2-1);
        else 
            return dp[l1][l2]=max(f(s1,s2,dp,l1-1,l2),f(s1,s2,dp,l1,l2-1));
       
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.size();
        int l2=text2.size();
        vector<vector<int>>dp(l1,vector<int>(l2,-1));
        return f(text1,text2,dp,l1-1,l2-1);
    }
};