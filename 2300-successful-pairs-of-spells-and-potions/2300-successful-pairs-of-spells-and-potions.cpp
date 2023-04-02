class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        
        for(int i=0;i<spells.size();i++)
        {
            // long long mini=(success+1)/spells[i];
            long long mini=ceil(double(success*1.0/spells[i]));
            int loc=lower_bound(potions.begin() , potions.end(), mini) - potions.begin() ;
            ans.push_back(potions.size()-loc);
        }
        return ans;
    }
};