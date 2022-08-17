class Solution {
     int climbStairs(int n,vector<int>& steps)
     {
        if(n==0||n==1)
            return steps[n]= 1;
        if(steps[n]!=-1)
            return steps[n];
       
        return steps[n]=climbStairs(n-2,steps)+climbStairs(n-1,steps);
     }
public:
    
    int climbStairs(int n) {
                    vector<int> steps(n+1,-1);
        return climbStairs(n,steps);
    }
};