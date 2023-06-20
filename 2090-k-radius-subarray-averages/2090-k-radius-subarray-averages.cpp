class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n,-1);
        long long  currSum=0;
        
        int i=0,j=0;
        int placeK=k;
        while(j<n)
        {
            
            currSum+=nums[j];
           
            // cout<<(2*k)+1<<endl;
            if(j-i+1<(2*k)+1)
            {
                j++;
                continue;
            }
            else if(j-i+1==(2*k)+1){
            //      cout<<"I"<<i<<" j"<<j<<endl;
            // cout<<"currSum"<<currSum<<endl;
            // cout<<"(2*k)+1-------------->"<<(2*k)+1<<endl;    
                ans[placeK++]=(currSum/((2*k)+1));
                currSum-=nums[i];
              i++;
            } 
            j++;
        }
        return ans;
    }
};