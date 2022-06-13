class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int>s;
        // for(int i=0;i<nums.size();i++)
        //     s.insert(nums[i]);
        // vector<int>temp(s.begin(),s.end());
        // nums=temp;
        // return s.size();
        // // for(int i=0,j=i;i<nums.size();i++)
        // // {
        // //     if(nums[i]!=nums[i+1])
        // //         continue;
        // //     if(nums[i]==nums[i+1])
        // //     {   
        // //         while(nums[i]==nums[i+1]&&i<nums.size())
        // //             i++;
        // //         nums
        // //     }   
        // // }
        int n=nums.size();
        int count = 0;
for(int i = 1; i < n; i++){
    if(nums[i] == nums[i-1]) count++;
    else nums[i-count] = nums[i];
}
return n-count;
    }
};