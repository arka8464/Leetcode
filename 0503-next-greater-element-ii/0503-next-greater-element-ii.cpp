class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        
        vector<int>ans(nums.size(),-1);
        
        stack<int>st;
        
        for(int i=0;i<2*nums.size()-1;i++)//imagine korbo je 2x len er array ta traverse korchi
        {
            while(!st.empty()&&nums[st.top()]<nums[i%nums.size()])
            {
                ans[st.top()]=nums[i%nums.size()];//ekhane prothom dik theke traverse korchi tai //st.top() jodi choto hoi tr mane etai amar next greater tai push marchi
                st.pop();
            }
             st.push(i%nums.size()); //ekhane direct index ta kei push korchi jate //alada kore map na banate hoi r jehetu arr ta 2*num.size obdhi jache tai ota ke % //lagiyechi
        }

        
        return ans;
    }
};