class LRUCache {
    map<int,list<int>::iterator > address;// to access the key  address fast without traversing the whole map
    // key ,iterator to the address
    map<int,int>mp;//to keep track of key,value pair
    list<int> l;// [double ended linked list]to keep track of the keys begin used
    //notun element gulo front e thakbe ar purono gulo pichone 
    int cap;//max capacity
    int sz;//current size of the list
public:
    LRUCache(int capacity) {
        sz=0;
        cap=capacity;
    }
    
    int get(int key) {
        /*
        returns the value if key present and push to list last   
        */
        if(mp.find(key)==mp.end())
            return -1;// not in the list
        
        auto it=address[key];// list e element er location
        l.erase(it);// delete korlm list theke 
        l.push_front(key);
        address[key]=l.begin();//notun location ta address e update korlm
        return mp[key];
        
        
    }
    /*
    eta new key hole last e dokhabe na hole key already present hole key update korbe ar last e pathabe 
   sz==cap hoye gele list er last element ta uriye debo
   */
    void put(int key, int value) {
        
         if(mp.find(key)!=mp.end())     
         {
              auto it=address[key];// list e element er location
              l.erase(it);// delete korlm list theke 
             
             sz--;// 
         }
        if(sz==cap)
        {
            auto it=l.back();//last element er address nilm
            address.erase(it);
            mp.erase(it);
            l.pop_back();
            sz--;
        }
        l.push_front(key);// prothom e pathalm 
        mp[key]=value;//notun value hole update korlm
        address[key]=l.begin();//notun address ta o update korlm
        
        sz++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */