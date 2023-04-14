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
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
          vector<vector<int>> dp(s.size(),vector<int>(s1.size(),-1));
        return lcs(s,s1,s.size()-1,s1.size()-1,dp);
    }
};