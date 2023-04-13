class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int i=0,j=0;
        
        while(i<pushed.size()&&j<popped.size())
        {
            // while(i<pushed.size()&&)
             st.push(pushed[i]);
            while(!st.empty()&&st.top()==popped[j])
                st.pop(),j++;
            i++;

        }
        // cout<<i<<" "<<j<<" "<<st.top()<<" "<<st.size()<<endl;
        // if(j<popped.size()&&st.top()!=popped[j])
        //     return false;
        return st.empty();
    }
};