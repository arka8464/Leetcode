class Solution {
    string f(string s)
    {
        int sm=0;
        for(int i=0;i<s.size();i++)
            sm+=(int)s[i]-'0';
        return to_string(sm);
    }
public:
    int addDigits(int num) {
        string s=to_string(num);
        
        while(s.size()>1)
        {
            s=f(s);
        }
        return stoi(s);
    }
};