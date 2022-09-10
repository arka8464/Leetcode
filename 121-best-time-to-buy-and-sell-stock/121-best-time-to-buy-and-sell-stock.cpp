class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //doing using kadane s algo
     int pft=0;
     int mini=prices[0];
    for(int i=1;i<prices.size();i++)
    {
        int pft_temp=prices[i]-mini;
         pft=max(pft_temp,pft);
        mini=min(mini,prices[i]);
    }
        return pft;
    }
};