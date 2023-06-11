class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> m(1001,0);
        
        for(auto it:trips)
        {
            int pickup=it[1];
            int dropoff=it[2];
         m[pickup] += it[0];
         m[dropoff] -= it[0];

        }
        
        int currCap=capacity;
       for(int i=0;i<1001&&currCap>=0;i++)
       {
           currCap-=m[i];
       }
        return currCap>=0;
    }
};