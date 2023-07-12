class Solution {
    bool checkPowerof5(int val)
    {
      if(val == 0) return false;
        while(val % 5 == 0)
            val /= 5; 
        return (val == 1);
    }
    int f(string s,int ind)
    {
        if(ind==s.size())
            return 0;// limit e pouche gele 
        
        if(s[ind]=='0')
            return 1e9; //jodi leading 0 thake tobe eita korbo
        
        int val=0;
        int ans=1e9;
        for(int i=ind;i<s.size();i++)
        {
            val=val*2+s[i]-'0';
            
            if(checkPowerof5(val))
               ans=min(ans,1+f(s,i+1)); 
        }
        return ans;
    }
public:
    int minimumBeautifulSubstrings(string s) {
        
        return f(s,0)==1e9?-1:f(s,0);
    }
};