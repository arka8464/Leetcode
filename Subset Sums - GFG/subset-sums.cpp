// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

void subsetSums(int ind, int sum, vector<int> &sumSubset, vector<int> &arr, int N)
    {
        if (ind == N)
        {
            sumSubset.push_back(sum);
            return;
        }
        // if picked
        subsetSums(ind + 1, sum + arr[ind], sumSubset, arr, N);
            // cout<<"a"<<endl
        // if not picked
        subsetSums(ind + 1, sum, sumSubset, arr, N);
    }
    
vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sumSubset;
         subsetSums(0, 0, sumSubset, arr, N);
         sort(sumSubset.begin(),sumSubset.end());
         return sumSubset;
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