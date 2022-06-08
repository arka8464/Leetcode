// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    void findPath(int r,int c,vector<vector<int>>&m,vector<string>&ans,string temp,int n,vector<vector<int>>&v)
    {
        if(r==n-1&&c==n-1)
        {
            ans.push_back(temp);
            return;
        }
        //downwards
        if(r+1<n&&v[r+1][c]==0&&m[r+1][c]==1)
        {
           v[r][c]=1;
           findPath(r+1,c,m,ans,temp+'D',n,v);
            v[r][c]=0;
        }
        //leftwards
        if(c-1>=0&&v[r][c-1]==0&&m[r][c-1]==1)
        {
           v[r][c]=1;
           findPath(r,c-1,m,ans,temp+'L',n,v);
            v[r][c]=0;
        }
         //rightwards
        if(c+1<n&&v[r][c+1]==0&&m[r][c+1]==1)
        {
           v[r][c]=1;
           findPath(r,c+1,m,ans,temp+'R',n,v);
            v[r][c]=0;
        }
        //upwards
        if(r-1>=0&&v[r-1][c]==0&&m[r-1][c]==1)
        {
           v[r][c]=1;
           findPath(r-1,c,m,ans,temp+'U',n,v);
            v[r][c]=0;
        }
       
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string temp;
        vector<vector<int>>v(n,vector<int>(n,0));
        if(m[0][0]==1)
        {
        findPath(0,0,m,ans,temp,n,v);
        }
        
        
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends