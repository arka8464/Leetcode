//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &a , int N){
       
       long currSum=0;
       for(int i=0;i<k;i++)
         currSum+=a[i];
         
       long maxi=currSum;
       
       int l=0,r=k;
       
      while(r<N)
      {
          //cout<<"l"<<l <<" r"<<r<<endl;
          currSum-=a[l];
          l++;
          currSum+=a[r];
          r++;
          
        
         maxi=max(maxi,currSum);     
      }
       return maxi;
       
    }
};

//{ Driver Code Starts.
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
} 
// } Driver Code Ends