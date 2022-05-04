class Solution {
    void reverseString(vector<char>& s,int start,int end)
    {
        if(start>end)
            return ;
        swap(s[start],s[end]);
        start++;
        end--;
        reverseString(s,start,end);
    }
public:
    void reverseString(vector<char>& s) {
        
        reverseString(s,0,s.size()-1);
    }
};