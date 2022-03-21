// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public://done  using sliding window method
    int maximumSumSubarray(int k, vector<int> &arr , int n){
    //   int i=0,j=0,sum=0;
    //   while(j<=K-1)
    //   {
    //       sum+=Arr[j];
    //       j++;
    //   }
    //   j--;
    //   int maxSum =sum;
    // while(j<N)
    //   {
    //       j++;
    //       sum-=Arr[i];
    //       sum+=Arr[j];
    //                  i++;
          
    //       if(sum>maxSum)
    //         maxSum=sum;
    //   }
      
    //   return maxSum;
    //     // code here 
     int curr_sum=0;
       int max_sum=INT_MIN;
       for(int i=0; i<k; i++)
       {
           curr_sum+=arr[i];
       }
       max_sum = max(curr_sum,max_sum);
       int start=0;
       for(int i=k; i<n; i++)
       {
           curr_sum+=-arr[start]+arr[i];
           if(curr_sum>max_sum)
           {
               max_sum = curr_sum;
           }
           
           start++;
       }
       return max_sum;
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