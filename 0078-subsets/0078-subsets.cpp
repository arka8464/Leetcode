class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int maxElement=(1<<nums.size()); //2^n
         vector<vector<int>> ans;
        for(int i=0;i<maxElement;i++)//sob gulo number er upor traverse korchi 
        {
            vector<int>temp;
            for(int j=0;j<nums.size();j++) //ebar sob number gulo r upor giye check korbo je ogulo oi digit gulo te bit set kora ache naki
            {
               if(i&(1<<j))//ekhane check korchi je bit gulo set kora ache naki
                   temp.push_back(nums[j]);
                
            }
            ans.push_back(temp);
        }
        return ans;    }
};