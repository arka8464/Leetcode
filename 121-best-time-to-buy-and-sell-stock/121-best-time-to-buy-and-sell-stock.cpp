class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //doing using kadane s algo
      int maxP=0;
        int mini=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            mini=min(mini,prices[i]);
            maxP=max(maxP,prices[i]-mini);
        }
        return maxP;
    }
};