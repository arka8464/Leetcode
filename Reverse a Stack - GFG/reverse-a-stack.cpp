//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    void insert(stack<int> &st,int tp)
    {
        if(st.empty())
          {st.push(tp);return;}
       int toop=st.top();
       st.pop();
       insert(st,tp);
       st.push(toop);
    }
public:
    void Reverse(stack<int> &st){
       if(st.size()<=1)
       return ;
       
       int tp=st.top();
       st.pop();
       Reverse(st);
       insert(st,tp);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends