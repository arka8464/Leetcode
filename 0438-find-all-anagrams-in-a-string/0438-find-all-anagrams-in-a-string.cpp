class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hashp(26,0);
        vector<int> hashs(26,0); 
        int k=p.size();
       
        
        for(int i=0;i<k;i++)
        {
            hashp[p[i]-'a']++;
        }
        vector<int>ans;
        
      
        // for(auto it:hashp)
        //     cout<<it<<" ";
        // cout<<"hashp"<<endl;
         // for(auto it:hashs)
         //    cout<<it<<" ";
         //  cout<<"hashs"<<endl;
        
        int l=0,r=0;
        while(r<s.size())
        {
            hashs[s[r]-'a']++;
            if(r-l+1<k)
            {
                r++;
                continue;
            }
            else if(r-l+1==k)
            {
                if(hashp==hashs)
                    ans.push_back(l);
                hashs[s[l]-'a']--;
              l++;
            }
       
            r++;
            
        }
        return ans;
    }
};