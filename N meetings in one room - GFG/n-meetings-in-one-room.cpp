// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    static bool comparator(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.second<b.second)
          return true;
        else if(a.second>b.second)
          return false;
        // else if (a.second==b.second)
        // {
            else return a.first<b.first;
            //   return true;
        // }
        // return false;
        
    }
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
      for(int i=0;i<n;i++)
      {
          v.push_back({start[i],end[i]});
      }
      
      sort(v.begin(),v.end(),comparator);
        
      int lst=v[0].second;
      int cnt=1;
    //   for(int i=0;i<n;i++)
    //   {
    //     //   cout<<lst<<endl;
    //      cout<<v[i].first<<" "<<v[i].second<<endl;
    //   }
      for(int i=1;i<n;i++)
      {
        //   cout<<lst<<endl;
         if(v[i].first>lst)
         {
             cnt++;
             lst=v[i].second;
         }
      }
      return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends