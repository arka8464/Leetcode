class Solution {
    int LCS(string &text1, string &text2,int ind1,int ind2,vector<vector<int>> &dp)
    {
        if(ind1<0||ind2<0)
            return 0;
        
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        if(text1[ind1]==text2[ind2])
            return 1 + LCS(text1,text2,ind1-1,ind2-1,dp);
        // if(text1[ind1]!=text2[ind2])
        else
            return dp[ind1][ind2]=0 + max(LCS(text1,text2,ind1,ind2-1,dp),LCS(text1,text2,ind1-1,ind2,dp));

    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.size();
        int l2=text2.size();
        vector<vector<int>> dp(l1,vector<int>(l2,-1));
        return LCS(text1,text2,l1-1,l2-1,dp);
    }
};