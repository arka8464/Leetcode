// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    long long maximumSumSubarray(int k, vector<int> &arr , int N){
       int i=0,j=0;
      long long int curr_Sum=0;
       
       while(j<=k+i-1){
        
         curr_Sum+=arr[j];
          j++;
       }
      long long int max_Sum=curr_Sum;
       for(;j<arr.size();i++,j++)
       {
           
            curr_Sum-=arr[i];
            curr_Sum+=arr[j];
           max_Sum=max(curr_Sum,max_Sum);
       }
       return max_Sum;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends