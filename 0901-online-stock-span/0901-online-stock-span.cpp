class StockSpanner {
    stack<pair<int,int>>s;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=1;
        if(s.empty())
        {
           s.push(make_pair(price,1));
            return s.top().second;
        }
        while(!s.empty()&&s.top().first<=price)
        {
            count+=s.top().second;
            s.pop();
        }
        s.push(make_pair(price,count));
        return s.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */