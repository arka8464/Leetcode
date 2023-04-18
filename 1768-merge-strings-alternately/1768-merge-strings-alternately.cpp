class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i=0;
        for(;i<word1.size()&&i<word2.size();i++)
        {
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        while(i<word1.size())
             ans.push_back(word1[i]),i++;
        
        while(i<word2.size())
             ans.push_back(word2[i]),i++;

        return ans;
    }
};