class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      unordered_map<char,int> sv;
      unordered_map<char,int> pv;
 vector<int>ans;
       for(int i=0;i<p.size();i++)pv[p[i]]++;
      
        int i=0,k=p.size(),j=0;
        
        while(j<s.size())
        {
            
            if(j-i+1<k)
            {
                sv[s[j]]++;
                j++;
            }
            else if(j-i+1==p.size())
            {
                
               sv[s[j]]++;

                cout<<i<<"i "<<j<<"j "<<endl;
               for (auto it = sv.begin(); it != sv.end(); ) 
               {
                           if (it->second == 0) 
                               it = sv.erase(it);
                             else    
                                 ++it;
               }
            //       for(auto it:sv)
            // //    { cout<<it.first<<" "<<it.second<<endl;}
            // // cout<<"loop"<<endl;
               if(sv==pv)
               {
                   ans.push_back(i);
               }
                 sv[s[i]]--;
              
               j++,i++; 
            }
          
        }
        return ans;
         
        
    }
};