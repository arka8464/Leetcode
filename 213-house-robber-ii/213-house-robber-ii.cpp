// class Solution {
//      int rob(int ind,vector<int>& dp,vector<int>& house)
//     {
//         if(ind==0)
//             return house[0];
//         if(ind<0)
//             return 0;
//            if(dp[ind]!=-1)
//             return dp[ind];
//          int pickIndex = house[ind]+ rob(ind-2,dp,house);   
//           int notpickIndex =0+ rob(ind-1,dp,house);
//         return dp[ind]=max(pickIndex,notpickIndex);
//     }
// public:
//     int rob(vector<int>& nums) {
//          int n=nums.size();
//         if(n==0)
//            return 0;
        
//         vector<int> dp1(n,-1);
//         vector<int> dp2(n,-1);

//         vector<int> temp1;
//         vector<int>temp2;
//         for(int i=0;i<n;i++)
//         {
//             if(i!=0)temp1.push_back(nums[i]);
//              if(i!=n-1)temp2.push_back(nums[i]);
//         }

//        // for(int i=0;i<n;i++)
//        //  {
//        //     cout<<temp1[i]<<" ";
//        //  } 
//        //  cout<<endl;
//        //   for(int i=0;i<n;i++)
//        //  {
//        //     cout<<temp2[i]<<" ";
//        //  } 
        
//         if(temp1.size()<3||temp2.size()<3)
//             return nums[1];
        
//         int v1=rob(n-1,dp1,temp1);
//        int v2=rob(n-2,dp2,temp2);
// // cout<<v1<<" "<<v2<<endl;
//        return  max( v1,v2);
//     }
// };
class Solution {
public:
    int houseRobber(vector<int>& nums) {
        
        int dp[nums.size()+1];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i=2; i<nums.size(); i++)
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        return dp[nums.size()-1];
    }
    
    int rob(vector<int>& nums) {
       
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
     
        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        return max(houseRobber(v1), houseRobber(v2));
    }
};