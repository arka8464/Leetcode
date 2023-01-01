class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int>ans(temp.size(),0);
        
        stack<pair<int,int>>s;
        
       for (int i = temp.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top().first <= temp[i]) {
            s.pop();
        }
        if (s.empty()) {
            ans[i] = 0;
        } else {
            ans[i] = s.top().second - i;
        }
        s.push(make_pair(temp[i], i));
    }
        return ans;
    }
};