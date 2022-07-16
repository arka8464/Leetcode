class Solution {
    bool caneat(vector<int>& piles,int k, int h)
    {
          long long hours = 0;
        for(int pile : piles){
            int div = pile / k;
            hours += div;
            if(pile % k != 0) hours++;
        }
        return hours <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       
         int mini=1,maxi=1e9;
        
       while(mini<=maxi)
       {
               int mid=mini+(maxi-mini)/2;
           if(caneat(piles,mid,h))
               maxi=mid-1;
           else
               mini=mid+1;
       }
       return mini; 
    }
};