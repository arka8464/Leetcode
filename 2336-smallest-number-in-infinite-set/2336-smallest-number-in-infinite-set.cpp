class SmallestInfiniteSet {
    priority_queue<int,vector<int>,greater<int>> pq;
    
    set<int> s;
public:
    SmallestInfiniteSet() {
       for (int i = 1; i <= 1000; i++) {
           pq.push(i);
           s.insert(i);
        } 
    }
    
    int popSmallest() {
        if(pq.empty())
            return NULL;
        int ans=pq.top();
        pq.pop();
        s.erase(ans);
        return ans;
    }
    
    void addBack(int num) {
        if(s.count(num)>0)
            return;
        s.insert(num);
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */