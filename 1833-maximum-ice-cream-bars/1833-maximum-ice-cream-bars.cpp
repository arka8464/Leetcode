class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());

        for (int i=0;i<costs.size();i++)
        {
            int temp=coins-costs[i];
            cout<<coins<<endl;
            if(temp<0)return i;
            else
                coins=temp;
        }
        return costs.size();
    }
};