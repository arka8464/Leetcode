class Solution {
    
public:
    void rotate(vector<int>& nums, int k) {
//         if(k==0||nums.size()<=1)
//             return ;
//       k=k%nums.size();
//         if(k==0)
//             return;
//         vector<int>ans;

//         for(int i=nums.size()-k;i<nums.size();i++)
//            ans.push_back(nums[i]);
//         for(int i=0;i<nums.size()-k;i++)
//             ans.push_back(nums[i]);
//         nums=ans;

        if(k==0||nums.size()<=1)
            return ;
      k=k%nums.size();

           if(k==0)
             return ;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());

    }
};