class Solution {
    void merge(vector<int>& nums1, vector<int>& nums2,vector<int>& ans)
    {
        int s1=nums1.size(),s2=nums2.size(),i=0,j=0;
        while(i<s1&&j<s2)
        {
          if(nums1[i]<=nums2[j])
          {
              ans.push_back(nums1[i]);
              i++;
          }
        else
             {
              ans.push_back(nums2[j]);
              j++;
          }   
              
        }
        
        while(i<s1)
        {
            ans.push_back(nums1[i]);
              i++;
        }
        
        while(j<s2)
        {
            ans.push_back(nums2[j]);
              j++;
        }
        
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        double med;
        vector<int> ans;
        merge(nums1,nums2,ans);
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