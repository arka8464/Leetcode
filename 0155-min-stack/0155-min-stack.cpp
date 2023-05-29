class MinStack {
     stack<int>st;
    priority_queue<int,vector<int>,greater<int>>pq;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        pq.push(val);
    }
    
    void pop() {
        stack<int>temp;
        while(!pq.empty())
        {
            if(pq.top()==st.top())
            {
                pq.pop();
                break;
            }
            temp.push(pq.top());
            pq.pop();
        }
        
        while(!temp.empty())
        {
            pq.push(temp.top());
            temp.pop();
        }
        
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        
       return pq.top(); 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */