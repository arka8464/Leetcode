class Solution {
    int f(vector<int>& nums1, vector<int>& nums2,int ind,int prevIndArr, vector<vector<int>>& dp)
    {
       if(ind==nums1.size()) // if we have used all numbers
        {
            return 0;
        }
        
        int ans=0;
     if(dp[ind][prevIndArr+1]!=-1e9)
        return dp[ind][prevIndArr+1];
        if(prevIndArr==-1)
        {
            ans=max(ans,1+f(nums1,nums2,ind+1,1,dp));//nums1 nichi
            ans=max(ans,1+f(nums1,nums2,ind+1,2,dp));//nums2 nichi
            ans=max(ans,f(nums1,nums2,ind+1,-1,dp));//skip marchi 
        }
        else
        {
            int prev=prevIndArr==1?nums1[ind-1]:nums2[ind-1];
            if(nums1[ind]>=prev)
                ans=max(ans,1+f(nums1,nums2,ind+1,1,dp));//nums1 nichi
            
            if(nums2[ind]>=prev)
                ans=max(ans,1+f(nums1,nums2,ind+1,2,dp));//nums2 nichi
            
           // ans=max(ans,f(nums1,nums2,ind+1,-1,dp));//skip marchi (marte parbo na karon ager ta ke already niye niyechi tai prevArrInd==-1 noi)  
        }
        return dp[ind][prevIndArr+1]=ans;
    }
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1,vector<int>(4,-1e9));
        return f(nums1,nums2,0,-1,dp);
    }
};