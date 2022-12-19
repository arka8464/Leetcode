class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       vector<int> ans(nums1.size(),-1);
        unordered_map<int,int>m;
        for(int i=0;i<nums1.size();i++)
            m[nums1[i]]=i;
        
        for(int i=0;i<nums2.size();i++)
        {
            auto it =m.find(nums2[i]);
            if(it!=m.end())
            {
                for(int j=i+1;j<nums2.size();j++)
                {
                    if(nums2[j]>nums2[i])
                    {
                        int ind=it->second;
                        ans[ind]=nums2[j];
                        break;
                    }
                 
                }
            }
           
        }
        return ans;
    }
};