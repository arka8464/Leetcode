#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n1,n2;
	    cin>>n1>>n2;
	    vector<int>v;
	    for(int i=0;i<n1;i++){
	        int temp;
	        cin>>temp;
	        v.push_back(temp);
	    }
	    sort(v.begin(),v.end());
	    for(int i=0;i<n1;i++)
	      cout<<v[i]<<" ";
	    cout<<endl;  
	     
	}
	
	return 0;
}