class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
      
        stringstream ss(s);
        
        string temp;
        while(ss>>temp)
            v.push_back(temp);
         
       int n=v.size();

        string ans;
        
        for(int i=n-1;i>=0;i--)
        {
            if(i!=n-1)
            {
                ans.push_back(' ');
            }
            ans+=v[i];
        }
        return ans;
    }
};