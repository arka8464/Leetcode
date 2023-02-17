//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int f(int *arr,vector<vector<int>> &dp,int i,int j)
    {
        if(i==j)
          return 0;
        
        if(dp[i][j]!=-1)
           return dp[i][j];
        
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int leftSteps=f(arr,dp,i,k);
            int rightSteps=f(arr,dp,k+1,j);
            int constSteps=arr[i-1]*arr[k]*arr[j];
            
            ans=min(ans,(leftSteps+rightSteps+constSteps));
        }
        return dp[i][j]= ans;
        
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return f(arr,dp,1,N-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends