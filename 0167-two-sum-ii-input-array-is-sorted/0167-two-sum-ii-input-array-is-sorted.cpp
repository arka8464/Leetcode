class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int low=0,high=num.size()-1;
        
        while(low<high)
        {
            
            if(num[low]+num[high]==target)
                return {low+1,high+1};
            else if(num[low]+num[high]<target)
                low++;
            else
                high--;
        }
        return {-1,-1};
    }
};