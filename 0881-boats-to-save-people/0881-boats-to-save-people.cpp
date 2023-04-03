class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        
         int upper=people.size()-1,lower=0;
        
        int ans=0;
       
      
           while(people[upper]>=limit&&upper>=0)
               ans++,upper--;
            
        
     while(upper>=lower)
     {
         int sum=people[upper]+people[lower];
         if(sum<=limit)
             ans+=1,upper--,lower++;
         else if(sum>limit)
              ans+=1,upper--;
     }
       
        return ans;
       
        
        
        
    }
};