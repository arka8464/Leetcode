#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> help(vector<int>& v,int k)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> ans;
   int i=0,n=v.size();
   for(;i<k;i++)
    pq.push(v[i]);
   
    for(;i<n;i++)
    {
        ans.push_back(pq.top());
        pq.pop();
        pq.push(v[i]);
    }
    while(!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n1,n2;
	    cin>>n1>>n2;
	    vector<int>v,ans;
	    for(int i=0;i<n1;i++)
	    {
	        int temp;
	        cin>>temp;
	        v.push_back(temp);
	    }
	    //sort(v.begin(),v.end());
	   ans= help(v,n2);
	    for(int i=0;i<n1;i++)
	      cout<<ans[i]<<" ";
	    cout<<endl;  
	     
	}
	
	return 0;
}