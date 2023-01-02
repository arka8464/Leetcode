class LRUCache {
   
public:
    unordered_map<int,int>m;
    unordered_map<int,list<int>::iterator> addr;

    list<int>l;
    int cap;
    int siz;
    LRUCache(int capacity) {
        cap=capacity;
        siz=0;
    }
    
    int get(int key) {
        
      if(m.find(key)==m.end())return -1;  //see if the element is present or not 
    
       l.erase(addr[key]);
         addr.erase(key);
        l.push_front(key);
         addr[key]=l.begin();
 
         return m[key]; 
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())//element is already 
        {
         l.erase(addr[key]);
         addr.erase(key);
         m[key]=value;
         siz--;
        }
        if(siz==cap)
        {
            addr.erase(l.back());
         m.erase(l.back());
                        l.pop_back();

         siz--;
        }
                l.push_front(key);
         addr[key]=l.begin();
         m[key]=value;
         siz++;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */