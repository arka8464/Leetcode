// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

/*Function to find frequency of x
* x : element whose frequency is to be found
* v : input vector
*/
#define ll long long
int findFrequency(vector<int> v, int x){
    // Your code here
    unordered_map<ll,ll>m;
    for(long long i=0;i<v.size();i++)
    {
        m[v[i]]++;
    }
    
    for(auto it:m)
    {
        if(it.first==x)
          return it.second;
    }
    return 0;
}

// { Driver Code Starts.
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    
	    // Declaring vector 
	    vector<int> v;
	        
	    // Taking vector element input
	    for(int i = 0;i<N;i++){
	        int k;
	        cin >> k;
	        v.push_back(k);
	    }
	    
	    // element whose frequency to be find
	    int x;
	    cin >> x;
	    cout << findFrequency(v, x) << endl;
	}
	
	return 0;
}  // } Driver Code Ends