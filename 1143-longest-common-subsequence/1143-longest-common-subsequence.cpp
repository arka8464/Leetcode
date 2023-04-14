class Solution {
    int lcs(string &text1, string &text2,int ind1,int ind2,vector<vector<int>> &dp)
    {
        if(ind1<0||ind2<0)return 0;
        
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        int match=0;
        if(text1[ind1]==text2[ind2])
         match=1+lcs(text1,text2, ind1-1, ind2-1,dp);
        
        int notMatch=0+max(lcs(text1,text2, ind1-1, ind2,dp),lcs(text1,text2, ind1, ind2-1,dp));
        
        return dp[ind1][ind2]=max(match,notMatch);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return lcs(text1,text2,text1.size()-1,text2.size()-1,dp);
    }
};