class KthLargest {
    priority_queue<int,vector<int>,greater<int>> pq;
    int K=0;
public:
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i=0;i<nums.size();i++)
            pq.push(nums[i]);
        
    }
    
    int add(int val) {
        
        pq.push(val);
        while(pq.size()>K){
            pq.pop();
        }
        return pq.top();
//          stack<int> st1;
//          while(!pq.empty())
//          {
//              cout <<pq.top()<<" ";
//              st1.push(pq.top());
//              pq.pop();
//          }
//         while(!st1.empty())
//         {
//             pq.push(st1.top());
//             st1.pop();
//         }
//         cout<<endl;
//         stack<int> st;
//         for(int i=0;i<K-1;i++)
//         {
//             st.push(pq.top());
//             pq.pop();
//         }
        
        
//         cout<<endl;

//         int ans=pq.top();
//         pq.pop();
        
//         while(!st.empty())
//         {
//             pq.push(st.top());
//             st.pop();
//         }
//         return ans;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */