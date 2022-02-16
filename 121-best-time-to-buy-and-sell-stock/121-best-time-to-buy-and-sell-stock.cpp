class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int pist=0;
        int max_p=0;
        int smollest=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<smollest)
                smollest=prices[i];
            pist=prices[i]-smollest;
            if(pist>max_p)
                max_p=pist;
        }
        return max_p;
        
    }
};