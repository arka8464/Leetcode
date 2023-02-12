//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
    // bool isPrime(Node*head)
    // {
    //     if(!head)return 0;
    //   int temp=head->val;
    //   for(int i=2;i<=pow(temp,(1/2));i++)
    //   {
    //       if(temp%i==0)
    //         return false;
    //   }
    //   return true;
    // }
    bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) return false;
  }
  return true;
}
int nearestPrime(int n)
{
     if(n==1)
            return 2;
    int l=n-1;
    int u=n+1; 
    while(1)
    {
        
    if(isPrime(l)&&isPrime(u))
     return l;
    else if(isPrime(l)) 
    return l;
    else if(isPrime(u)) 
    return u;
    if(l>=1)
        l--;
    u++;
    }
    // while(1)
    // {
    //   if(isPrime(u)) 
    // return u;
    //  ,u++;  
    // }
}
public:
    Node *primeList(Node *head){
        Node* ptr1=head;
        // unordered_map<int,int>m;
        vector<int>v;
        while(ptr1)
        {
           v.push_back(ptr1->val);
           ptr1=ptr1->next;
        }
        
        
        
        for(int i=0;i<v.size();i++)
        {
           
            if(isPrime(v[i]))
              continue;
            v[i]=nearestPrime(v[i]);
        }
        
        
        // for(int i=0;i<v.size();i++)
        // {
        //     cout<<"v[i]"<<v[i]<<" ";
        // }
        Node *dummy = new Node(-1);
        Node *ptr=dummy;
        for(int i=0;i<v.size();i++)
        {
           Node *newNode= new Node(v[i]);
           ptr->next=newNode;
           ptr=ptr->next;
        }
        return  dummy->next;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends