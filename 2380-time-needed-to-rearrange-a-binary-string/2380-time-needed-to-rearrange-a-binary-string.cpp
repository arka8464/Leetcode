class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
     int count=0;
       int n=s.size();
       
     for(int i=0;i<n;i++)
     {
         bool temp=false;
         for(int j=0;j<n-1;j++)
         {
             if(s[j]=='0'&&s[j+1]=='1')
             {
                s[j]='1';
                s[j+1]='0'; 
                 j++;
              temp=true;

             }
         }
         if(temp==true)count++;
     }
        
        return count;
    }
};