class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.empty())
            return 0;
        int i=0,j=0,maxi=INT_MIN;
        int n=s.size();
        unordered_map<char,int>m;
        while(j<n)
        {
            m[s[j]]++;
            // cout<<"i "<<i<<" j "<<j<<endl;
            if(m.size()>j-i+1)//if number of unique characters is lesser than the window size we increase the window size
                j++;
            else if(m.size()==j-i+1)
            {
                maxi=max(maxi,j-i+1);
                j++;
            }
            else if (m.size()<j-i+1)//this means that the number of unique character is lesser than the window size 
            {
                while(m.size()<j-i+1)
                {
                    m[s[i]]--;
                    if(m[s[i]]==0)
                      m.erase(s[i]);
                    i++;
                }
                   j++;
            }
        }
   return maxi;
    
    }
};