class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxiEle=nums[0], maxiCnt=1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(maxiCnt==0)
            {
                maxiCnt++;
                maxiEle=nums[i];
            }
            else if(maxiEle==nums[i])
            {
               maxiCnt++; 
            }
            else
               maxiCnt--;

        }
        
        return maxiEle;
    }
};