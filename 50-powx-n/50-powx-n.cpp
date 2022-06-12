class Solution {
public:
    double myPow(double x, int n) {
       double ans=1.0;
        long long p=n;//making a copy of the power to keep the original value
        
        if(p==1)
            return x;
        if(p<0)
            p=-p;//equating the negative power to the positive power and will later change it while returning 
        while(p>0)
        {
            if(p%2!=0)
            {
                ans*=x;//if power is odd we keep pow(1) separate and proceed further
            }
            p=p/2;//reducing the power by 2 
            x=x*x; //multiliying the base by itself 
        }
        if(n<0)
            return 1/ans;
        return ans;
    }
};
/*
Approach using STL
double ans=pow(x,n);
        return ans;
*/