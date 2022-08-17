class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),i,j;
        for( i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
                break;
        }
        if(i<0)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(j=n-1;j>=0;j-- )
            {
                if(nums[j]>nums[i])
                    break;
            }
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
        }
    }
};

// INBUILT STL
//  next_permutation(nums.begin(),nums.end());

// The next approach is generating all the permutations and then storing it in the ans vector of vector and then iterating it to find the next iteration 

//T.C will be O(n!* n)

