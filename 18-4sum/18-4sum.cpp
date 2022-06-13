class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
       vector<vector<int>> ans;
        int n=nums.size();
        if(n<=0)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int front=j+1,back=n-1;
                int target2=target-(nums[i]+nums[j]);
                while(front<back)
                {
                    int curr_Sum=nums[front]+nums[back];
                    if(curr_Sum>target2) 
                        back--;
                    else if(curr_Sum<target2)
                        front++;
                    else if(curr_Sum==target2)
                    {
                        vector<int> t(4,0);
                        t[0]=nums[i];
                         t[1]=nums[j];
                        t[2]=nums[front];
                        t[3]=nums[back];
                        ans.push_back(t);
                    
                    while(front<back&&nums[front]==t[2])//skipping duplicates of item3
                        front++;
                        
                    while(front<back&&nums[back]==t[3])//skipping duplicates of item 4
                        back--;                    
                }
                while(j+1<n&&nums[j+1]==nums[j])
                    j++;
            }
             while(i+1<n&&nums[i+1]==nums[i])
                    i++;
        }
    }
        return ans;
    }
};