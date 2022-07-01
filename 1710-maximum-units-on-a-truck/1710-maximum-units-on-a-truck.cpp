class Solution {
    static bool compare(vector<int>&a,vector<int>&b)
    {
        // if(a>b)
        //     return true;
        // else 
        //     return false;
        return a[1]>b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int ans=0;
        for(auto it:boxTypes)
        {
          int temp = min(it[0],truckSize);
            truckSize-=temp;
            ans+=(temp*it[1]);
            if(truckSize==0)
                break;
        }
        return ans;
    }
};