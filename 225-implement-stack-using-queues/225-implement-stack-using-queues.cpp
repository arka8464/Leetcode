class MyStack {
public:
    queue<int> fq,sq; 
    
    MyStack() {
       
    }
    
    void push(int x) {
        if(fq.size()==0)
            fq.push(x);
        else
        {
            while(!fq.empty())
            {
                sq.push(fq.front());
                fq.pop();
            }
            fq.push(x);
            while(!sq.empty())
            {
                fq.push(sq.front());
                sq.pop();
            }
        }
    }
    
    int pop() {
        int element =fq.front();
        fq.pop();
        return element;
    }
    
    int top() {
        return fq.front();
    }
    
    bool empty() {
        return fq.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */