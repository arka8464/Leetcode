//bascially we have to find the nearest y <=x such that ny*Y<=x
class Solution {
public:
    int mySqrt(int x) {
        int low= 0,high= x;
        int ans=0;
        while(low<=high)
        {
           long long  mid=low+(high-low)/2;
            // long long root=mid*mid;
            if(mid*mid<= x)
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};