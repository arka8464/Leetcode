class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>m;
        
        for(auto it:trips)
        {
            int pickup=it[1];
            int dropoff=it[2];
         m[pickup] += it[0];
         m[dropoff] -= it[0];

        }
        
        int currCap=0;
        for(auto it:m)
        {
            currCap+=it.second;
            if(currCap>capacity)
                return false;
        }
        return true;
    }
};