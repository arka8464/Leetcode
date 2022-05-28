class Solution {
     void reverseString(vector<char>& s,int start,int end) {
        
         if(start>=end)
             return;
         char c=s[start];
         s[start]=s[end];
         s[end]=c;
         cout<<s[start]<<" "<<s[end]<<endl;
         start=start+1;
         end=end-1;
         reverseString(s,start,end);
         
    }
public:
    void reverseString(vector<char>& s) {
        
        reverseString(s,0,s.size()-1);
    }
};