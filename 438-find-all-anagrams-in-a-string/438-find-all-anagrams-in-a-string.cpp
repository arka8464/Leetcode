class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> shash(26,0);
        vector<int> phash(26,0);
        int i=0,j=0;
        int k=p.size();
        vector<int> ans;
        if(s.size()<k)
        {
            return ans;
        }
        for(int i=0;i<p.size();i++)
        {
            phash[p[i]-'a']++;
        }
        //  for(int i=0;i<26;i++)
        // {
        //     cout<<phash[i]<<" ";
        // }
        while(j<s.size())
        {
            if(j<k+i-1)
            {
                shash[s[j]-'a']++;
                j++;
                     
                continue;
            }
        
            else if(j==k+i-1)
            {
                // cout<<"i "<<i<<" "<<"j "<<j<<endl;
         
                // cout<<endl;
                 shash[s[j]-'a']++;
        //             for(int i=0;i<26;i++)
        // {
        //     cout<<shash[i]<<" ";
        // }
        //         cout<<endl;
                if(phash==shash)
                    ans.push_back(i);
                shash[s[i]-'a']--;
                i++;          
            }
                       
            j++;
        }
        return ans;
    }
};