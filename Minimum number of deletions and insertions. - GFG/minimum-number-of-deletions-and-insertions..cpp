//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
 int LCS(string s1,string s2)
    {
        int l1=s1.size();
        int l2=s2.size(); 
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,-1));
        //we don't represent the base case involving 0 for negative indexes 
        //instead we do them for zero 
        for(int i=0;i<=l1;i++)dp[i][0]=0;
        for(int i=0;i<=l2;i++)dp[0][i]=0;
        
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                 if(s1[i-1]==s2[j-1])
            dp[i][j]= 1+ dp[i-1][j-1];
        else 
             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[l1][l2];
    } 
    
	public:
	int minOperations(string s1, string s2) 
	{ 
	    // Your code goes here
	    return abs(s1.size()-LCS(s1,s2))+ abs(s2.size()-LCS(s1,s2));
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends