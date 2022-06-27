class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(auto it:s)
            m[it]++;
        priority_queue<pair<int,int>> pq;
        for(auto it:m)
            pq.push({it.second,it.first});
        
        string ans;
       while(!pq.empty())
        {
            int no=pq.top().first;
            while(no--)
            {
                ans.push_back(pq.top().second);
            }
           pq.pop();
        }
        return ans;
    }
};