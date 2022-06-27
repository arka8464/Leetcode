class Solution {
public:
    int minPartitions(string n) {
         char c='0';
        for(int i=0;i<n.size();i++)
        {
            if(n[i]-'0'>c-'0')
                c=n[i];
        }
        return (int )(c-'0');
    }
};