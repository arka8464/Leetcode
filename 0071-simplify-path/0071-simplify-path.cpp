
class Solution {
public:
    string simplifyPath(string s) {
        stack<string>st;
       string ans;
        
        for(int i=0;i<s.size();i++)
        {
           if(s[i]=='/')continue;
           string temp;
            while(i<s.size()&&s[i]!='/')
                temp+=s[i],i++;
            
           if(temp==".")continue;

            if(temp=="..")
            {
                if(!st.empty())
                    st.pop();
            }
            else
            {
                st.push(temp);
            }
        }
        
        while(!st.empty())
        {
            ans='/'+st.top()+ans;//we cannot use ans+= here becasue the contents of the stack are oin reverse order thus the answer will give be in reverse manner 
            st.pop();
        }
        
        if(ans.size()==0)
            ans.push_back('/');
        return ans;
        
    }
};