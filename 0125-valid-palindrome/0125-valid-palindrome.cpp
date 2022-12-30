class Solution {
public:
    bool isPalindrome(string s) {
        
        s.erase(remove(s.begin(),s.end(),' '),s.end());
        for(int i=0;i<s.size();i++)
        {
            s[i]=tolower(s[i]);
        } 

        string s1;
         for(int i=0;i<s.size();i++)
        {
            if(isalnum(s[i]))
           s1.push_back(s[i]);                    
         } 
        
        s=s1;
        reverse(s.begin(),s.end());
              
        cout<<s<<endl;
        cout<<s1<<endl;

        if(s==s1)return true;
        return false;
        

        // return true;
    }
};