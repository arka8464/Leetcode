class Solution {
public:
    int strStr(string haystack, string needle) {
        
      string str="";

       
        
        int i=0,j=0;
        
        while(j<haystack.size())
        {
             str+=haystack[j];
            if(j-i+1<needle.size())   
                j++; 
            
         else if(j-i+1==needle.size())
            {
                        
               if(str==needle)
                    return i; 
                else
                {
                   str.erase(str.begin());
                    i++,j++;
                }
            }
            
        }    
        
        return -1;
        
    }
};