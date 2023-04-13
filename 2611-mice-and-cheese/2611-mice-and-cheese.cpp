
class Solution {
   
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<reward1.size();i++)
            v.push_back({reward1[i]-reward2[i],i});
        
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        int ans=0;
        // int secCnt=reward1.size()
        // for(auto it:v)
        //     cout<<it.first<<" "<<it.second<<endl;
        int i=0;
        for(;i<k;i++)
           {
            ans+=reward1[v[i].second];
           }
        
        // sort(v.begin(),v.end(),compare2);
        for(;i<reward2.size();i++)
           {
            ans+=reward2[v[i].second];
        }
        return ans;
    }
};