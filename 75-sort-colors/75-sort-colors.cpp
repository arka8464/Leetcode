class Solution {
    void insert(vector<int>& nums,int last)
    {
        if(nums.size()==0||nums.back()<=last)
        {
            nums.push_back(last);
            return;
        }
        int temp =nums.back();
       nums.pop_back();
        insert(nums,last);
        nums.push_back(temp);
            
    }
public:
    void sortColors(vector<int>& nums) {
      if(nums.size()<=1)
          return;
       int last=nums.back();
        // cout<<last<<endl;
       nums.pop_back();
        sortColors(nums);
        insert(nums,last);
    }
};