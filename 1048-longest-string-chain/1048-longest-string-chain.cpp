class Solution {
   bool f(string &s1, string &s2)
{
    if(s1.length()-s2.length()!=1) return false;
    int i=0,j=0;
    while(i<s1.length())
    {
        if(s1[i]==s2[j])
        {
            i++;j++;
        }
        else
            i++;
    }
    if(i==s1.length() && j== s2.length()) return true;
    else return false;
}
   static bool comp(string &s1,string &s2)
    {
        return s1.size()<s2.size();
    }
//     int f(vector<string>& words,int ind,int next)
//     {
//         if(ind<0)
//             return 0;
//         if (words[next].size()-words[ind].size()!=1)
//             return 0;
//         sort(words.begin(),words.end(),comp);
//         int pick=0,notPick=0;
//         if(next==-1||predecessor(words[ind],words[next]))
//             pick=1+f(words,ind-1,ind);
        
//         notPick=f(words,ind-1,next);
        
//         return max(pick,notPick);
//     }
public:
    int longestStrChain(vector<string>& words) {
        
        // string a="cxbc",b="pcxbc";
        // cout<<predecessor(a,b);
        // return f(words,words.size()-1,-1);
    // return -1;
       int n=words.size();
                if(n<2)
return n;
       sort(words.begin(),words.end(),comp);

        vector<int>dp(n,1);
        int maxi= 0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(f(words[i],words[j])&& dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                }
            }
             maxi = max(maxi,dp[i]); 
        }
        return maxi;
        
        }
};