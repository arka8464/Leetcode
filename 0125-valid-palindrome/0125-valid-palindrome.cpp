class Solution {
public:
    bool isPalindrome(string s) {
        
        string newS;
        for(int i=0;i<s.size();i++)
        {
            if(isalnum(s[i]))
               {
                newS+=tolower(s[i]);
            }
        }
        string newS2=newS;
        reverse(newS.begin(),newS.end());
        
        return newS2==newS;
    }
};