class Solution {
    int f(string& word1, string& word2,int l1,int l2, vector<vector<int>>&dp)
    {
        if(l1<0)
            return l2+1;
         if(l2<0)
            return l1+1;
        if(dp[l1][l2]!=-1)
            return dp[l1][l2];
        int ans=0;
        if(word1[l1]==word2[l2])//if matching
            return  f(word1,word2,l1-1,l2-1,dp);
        else
        {
            int del = 1+f(word1,word2,l1-1,l2,dp);
            int replace =1+ f(word1,word2,l1-1,l2-1,dp);
            int insert= 1+f(word1,word2,l1,l2-1,dp);
            ans= min(del,min(replace,insert));
        }
        return dp[l1][l2]=ans;
    }
public:
    int minDistance(string word1, string word2) {
        int l1=word1.size();
        int l2=word2.size();
        vector<vector<int>>dp(l1,vector<int>(l2,-1));
        
        return f(word1,word2,l1-1,l2-1,dp);
        
        
    }
};