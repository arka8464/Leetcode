class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        long long prdct=1;
        vector<int >prefix(n);
        vector<int >suffix(n);

        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        
        for(int i=1;i<n;i++)
            prefix[i]=prefix[i-1]*nums[i];
        
        
        for(int i=n-2;i>=0;i--)
            suffix[i]=suffix[i+1]*nums[i];
        
        
        for(auto it:prefix)
            cout<<it<<" ";
        cout<<"prefix"<<endl;
        for(auto it:suffix)
            cout<<it<<" ";
        cout<<"suffix"<<endl;
        for(int i=0;i<n;i++)
        {
           if(i!=0&&i!=n-1)
            ans.push_back(prefix[i-1]*suffix[i+1]);
          
            if(i==0)
                ans.push_back(suffix[1]);
            if(i==n-1)
                ans.push_back(prefix[n-2]);
        }
        
        
        return ans;
        

    }
};