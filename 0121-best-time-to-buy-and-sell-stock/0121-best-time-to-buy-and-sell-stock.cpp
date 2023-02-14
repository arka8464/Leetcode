class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            int temp=prices[i]-mini;
            ans=max(ans,temp);
            mini=min(mini,prices[i]);
        }
return ans;
    }
};