class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int fi=0,li=numbers.size()-1;
        while(fi<=li)
        {
            int sum=numbers[li]+numbers[fi];
            if(sum==target)
            {
                ans.push_back(fi+1);
                ans.push_back(li+1);
                return ans;
            }
            if(sum>target)
                li--;
            if(sum<target)
                fi++;
        }
        return ans;
    }
};