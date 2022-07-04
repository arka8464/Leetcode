// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
    void subsetSums(int ind,vector<int>& arr, int size,int tempSum,vector<int>& ans)
    
    {
        if(ind==size)
        {
            ans.push_back(tempSum);
            return ;
        }
        tempSum+=arr[ind];
        subsetSums(ind+1,arr,  size, tempSum,ans);
        tempSum-=arr[ind];
        subsetSums(ind+1,arr,  size, tempSum,ans);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        subsetSums(0,arr,arr.size(),0,ans);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends