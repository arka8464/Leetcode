class Solution {
   static bool compare(vector<int>&  a,vector<int>&  b)
    {
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),compare);
        int ans=1;
        // vector<vector<int>>& v;
        // for(auto it:points)
        // {
        //     for(auto t:it)
        //         cout<<t<<" ";
        //     cout<<","<<endl;
        // }
        int lstpt=points[0][1];
        for(auto it:points)
        {
            if(it[0]>lstpt)
            {
                ans++;
                lstpt=it[1];
            }
           lstpt=min(lstpt,it[1]); 
        }
        return ans;
    }
};