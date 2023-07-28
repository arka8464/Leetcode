class Solution {
public:
    bool checkValidString(string s) {  
        int minP=0,maxP=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                minP++,maxP++;
            else if(s[i]==')')
               minP=max(minP-1,0),maxP--;
            else
                maxP++,minP=max(minP-1,0);
            if(maxP<0)
                return false;
  
        }
        return minP==0;
//         stack<char>st;
//         st.push(s[0]);
//         if(st.top()==')')
//             return false;
//         for(int i=1;i<s.size();i++)
//         {
//            if(st.top()=='*'||st.top()=='('&&s[i]==')')
//                st.pop();
//             else 
//                 st.push(s[i]);
//            // if(s.top()=='*'&&s[i]=='(') 
//         }
        
        
//         while(!st.empty())
//         {
//             cout<<st.top()<<endl;
//              st.pop();
//         }
//         //  while(!st.empty()&&st.top()!='(')
//         // {
//         //     cout<<st.top()<<endl;
//         //      st.pop();
//         // }
//         return st.size()==0;
    }
};