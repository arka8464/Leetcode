class Solution {
   
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        double med;
        vector<int> ans;
        // merge(nums1,nums2,ans);
        ans.insert(ans.end(),nums1.begin(),nums1.end());
        ans.insert(ans.end(),nums2.begin(),nums2.end());
       sort(ans.begin(),ans.end());
        int sz=ans.size();
        if(sz%2!=0)
            med=ans[sz/2]/1.0;
        else
        {
            int temp1=ans[sz/2]/1.0;
            int temp2=ans[(sz-1)/2]/1.0;
 
            med=(temp1+temp2)/2.0;
        }
            return med;
    }
};