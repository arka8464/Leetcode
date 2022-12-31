class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>m;
        
//here the longest window can be j-i+1==k+(max_frequency of the char in this window )
        //j-i+1-maxCnt==k
        int i=0,j=0, maxCnt=0;//maxCnt==to keep track of the max in the window 
        int ans=INT_MIN;
        while(j<s.size())
        {
            m[s[j]]++;
            maxCnt=max(maxCnt,m[s[j]]);

            if(j-i+1-maxCnt>k)//if the window size becomes greater than k this means that the window is not valid and we will have to increase i
            {
               m[s[i]]--;
               if(m[s[i]]==0)m.erase(s[i]);
                i++;
            }
            ans=max(ans,j-i+1);
                j++;
        }
        return ans;
        
    }
};