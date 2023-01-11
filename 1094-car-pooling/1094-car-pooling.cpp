class Solution {
    // static bool compare(vector<int>&a,vector<int>&b)
    // {
    //     return a[1]<b[1];
    // }
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
         // for(auto it:trips)
         //    for(auto it1:it)
         //        cout<<it1<<" ";
        vector<pair<int,int>> v;
        
        for(int i=0;i<trips.size();i++)
        {
            // cout<<i<<" "<<ans.back()[0]<<" "<<ans.back()[1]<<" "<<ans.back()[2];
          v.push_back(make_pair(trips[i][1],trips[i][0]));
          v.push_back(make_pair(trips[i][2],-trips[i][0]));

        }
               sort(v.begin(),v.end());

//         for(auto it:ans)
//             for(auto it1:it)
//                 cout<<it1<<" ";
        int curr_cap=0;
        for(int i=0;i<v.size();i++)
        {
            curr_cap+=v[i].second;
            if(curr_cap>capacity)return false;
        }
        return true;
    }
};