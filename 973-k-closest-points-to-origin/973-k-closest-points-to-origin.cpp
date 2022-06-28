# define  ppi  pair<double,pair<int,int>>
class Solution {
    // static bool compare (ppi&a,ppi&b )
    // {
    //     if(a.first>a.second)
    //         return true;
    //     else if ()
    // }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       vector<vector<int>> ans;
       priority_queue<ppi> pq;
        
        for(int i=0;i<points.size();i++)
        {
            double temp=sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            pq.push({temp,{points[i][0],points[i][1]}});
                            cout<<pq.top().first<<" "<<pq.top().second.first<<" "<<pq.top().second.second<<endl;

            if(pq.size()>k)
            {
                // cout<<pq.top().second.first<<pq.top().second.second<<endl;
                pq.pop();
          }
        }
        
        while(!pq.empty())
        {
            vector<int> temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second);
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
    }
};