class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>m;
        
        for(auto it:nums)
            m[it]++;
        
        int ans=0;
         // for(auto it:m)
         //    cout<<it.first<<" "<<it.second<<" elements"<<endl;
        
        
//         for(auto it:m)
//         {
//             int num=it.first;
//             int freq=it.second;
            
//             if(m.find(it))
//         }
        for(auto it=m.begin();it!=m.end();it++)
        {
            int temp=1;
            while(m.find(it->first+1)!=m.end())
            {
                // cout<<temp<<" "<<it->first<<" "<<it->second<<endl;
               temp++,it++; 
            }
            if(temp>ans)
                ans=temp;
        }
        
        return ans;
        
    }
};