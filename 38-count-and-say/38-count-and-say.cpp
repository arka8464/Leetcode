class Solution {
public:
    string countAndSay(int n,string s="1") {
        
        if(n==1)
            return s;
        
       int i=0,len=s.size();
        string ans="";
        while(i<len)
        { 
                int j=i;
                while(s[i]==s[j]&&i<s.size())
                {
                    cout<<s[i]<<endl;
                    i++;
                }
            ans+=to_string(i-j)+s[j];
        }
        return countAndSay( n-1,ans);
    }
};