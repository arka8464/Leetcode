class Solution {
   
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n<2)
            return nums;
        vector<int>prev(n);
        
        for(int i=0;i<n;i++)
            prev[i]=i;
        
        vector<int>dp(n,1);
        int maxIdx=-1;
        int maxEle=-1;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                                                            // cout<<i<<" "<<j<<endl;
                // cout<<nums[i]%nums[j]<<" "<<nums[j]%nums[i]<<endl;
                if(nums[i]%nums[j]==0)
               {

                    if(dp[j]+1>dp[i])
                    {
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                        if(dp[i]>maxEle)
                       { maxIdx=i;
                        maxEle=dp[i]; }   
                    }
                    
                }
                
            }
        }
         
        //  for(int i=0;i<n;i++)
        //  cout<<dp[i]<<" ";
        // cout<<endl;
        //  for(int i=0;i<n;i++)
        //  cout<<prev[i]<<" ";
        // cout<<endl;
        // cout<<maxEle<<endl;
        // cout<<maxIdx<<endl;

        // cout<<endl;

        vector<int>ans;
        if(maxIdx==-1)
            return {nums[0]};
        int idx=maxIdx;
        ans.push_back(nums[idx]);

        while(prev[idx]!=idx)
        {
            // cout<<"idx"<<idx<<"prev[idx]"<<prev[idx]<<endl;
            idx=prev[idx];
            ans.push_back(nums[idx]);
        }
        return ans;
    }
};