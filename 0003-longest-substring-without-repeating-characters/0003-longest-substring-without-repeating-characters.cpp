class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int i=0,j=0,ans=0;
        unordered_map<char,int>m;
      if(s.size()<=1)  return s.size(); 
        
        while(j<s.size())
        {
            m[s[j]]++;
           
             if(m.size()<j-i+1)
            {
                while(m.size()<j-i+1&&m.size()>0)
                {
                    m[s[i]]--;
                    if(m[s[i]]==0)
                        m.erase(s[i]);
                    i++;
                }
                         j++;

            }
           
          else if(m.size()==j-i+1)
          {
            //    if(j-i+1>ans)
            // {
            //     cout<<i<<" "<<j<<" "<<j-i+1<<endl;
            // }
              ans=max(ans,j-i+1);
                  j++;

          } 
        }
        return ans;
    }
};