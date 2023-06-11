class Solution {
    // static bool compare(const vector<int>& a, const vector<int>& b) {
    //     if (a[1] == b[1])
    //         return a[0] <= b[0];
    //     return a[1] < b[1];
    // }

public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> m;

        for (int i = 0; i < intervals.size(); i++) {
            m[intervals[i][0]] = i;
        }

        // sort(intervals.begin(), intervals.end(), compare);

        vector<int> ans;

        for (int i = 0; i < intervals.size(); i++) {
           //implement changes here 
            auto it =m.lower_bound(intervals[i][1]);
            if(it!=m.end())
            {
                ans.push_back(it->second);
            }
            else
              ans.push_back(-1);
 
        }

        return ans;
    }
};
