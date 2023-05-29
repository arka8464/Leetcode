//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    long long  sumDigit(long long num)
    {
        long long sum=0;
        
        while(num>0)
        {
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
  public:
    long long getCount(long long N , long long D) {
        // code here
        
        long long low=0,high =N;
        long long start=0;
        while(low<=high)
        {
            long long mid = low+(high-low)/2;
            if(abs(sumDigit(mid)-mid)>=D)
            {
                start=mid;
                high=mid-1;
            }
            // else if(abs(sumDigit(mid)-mid)>D)
            // {
            //     high=mid-1;
            // }
            else
             low=mid+1;
        }
        
        //cout<<start<<" start"<<endl;
        if(start==0)
          return 0;
        
        return (N-start)+1;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N,D;

        cin>>N>>D;

        Solution ob;
        cout << ob.getCount(N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends