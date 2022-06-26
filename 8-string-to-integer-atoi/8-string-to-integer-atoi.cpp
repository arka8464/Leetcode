class Solution {
public:
    int myAtoi(string s) {
      
        
        int sign=+1,i=0;
        int ans=0;
       int n=s.size();
       
    
         while(s[i]==' '&&i<n)
                 i++;
        
        if(s[i]=='-' || s[i]=='+')
        {
            if(s[i]=='-' )
                sign = -1;
            i++;
        }
        
       for(; i< s.length() && s[i]>='0' && s[i] <='9';){
            int no = s[i] - '0';
            if(((ans) > (INT_MAX/10)) || (ans == INT_MAX / 10 && s[i] - '0' > 7)){
                return sign ==1 ? INT_MAX : INT_MIN;
            }        
            ans = ans*10 + no;
            i++;
        }
        return ans * sign;
            
        
    
    }
};

/* STL shiz
  stringstream ss(s);
        int ans=0;
        ss>>ans;
        return ans;
*/