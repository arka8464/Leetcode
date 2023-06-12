class MyCalendar {
    map<int,int>m;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        m[start]++;//increasing start +=1
        m[end]--;   //decreasing start -=1
        //now the sum should not become more than 1 at any point in time because then it means that before decreasing the value we have increemented the value of insert
       int sum=0;
        for(auto it:m)
       {
            sum+=it.second;
            if(sum>1)
        {
             m[start]--;//increasing start +=1
        m[end]++;  //reversing the things done earlier becasue we are not adding the     elemenets given in the function 
            return false;
        }}
return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */