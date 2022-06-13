// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
#include<bits/stdc++.h>
class Solution{
  public:
    int longestKSubstr(string s, int k) {
    int i=0,j=0,maxi=INT_MIN;
    int n=s.size();
    unordered_map<char,int>m;
    while(j<n)
    {
        m[s[j]]++;
        
        if(m.size()<k)
          j++;
        else if(m.size()==k )
        {
            maxi=max(maxi,j-i+1);
            j++;
        }
        else if(m.size()>k )
        {
            while(m.size()>k)
            {
                m[s[i]]--;
                if(m[s[i]]==0)
                {
                    m.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    if(maxi==INT_MIN)
     return -1;
    return maxi;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends