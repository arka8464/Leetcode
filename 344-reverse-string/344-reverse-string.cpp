class Solution {
   void reverseString(vector<char>& s,int start,int end)
   {
       if(start>=end)
           return ;
       char temp=s[start];
       s[start]=s[end-1];
       s[end-1]=temp;
       return reverseString( s,start+1,end-1);
   }
public:
    void reverseString(vector<char>& s) {
        
         return reverseString( s,0,s.size());
    }
};