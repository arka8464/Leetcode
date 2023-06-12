class MyCalendarThree {
        map<int,int>m;

public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;//increasing start +=1
        m[end]--;   //decreasing start -=1
        //now the sum should not become more than 1 at any point in time because then it means that before decreasing the value we have increemented the value of insert
       int sum=0;
        int ans=1;
        for(auto it:m)
       {
            sum+=it.second;
             
          ans=max(ans,sum);
        }
return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */