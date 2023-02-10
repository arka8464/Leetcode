class Solution {
   bool f(string& s,string& p,int l1,int l2,vector<vector<int>> &dp)
   {
       if(l1<0&&l2<0){           cout<<"1"<<endl;
return true;}
       if(l1>=0&&l2<0)
       {
                      cout<<"2"<<endl;
return false;}
       
       if(l1<0&&l2>=0)
       {
           for (int j = 0; j <= l2; j++) {
    if (p[j] != '*')
      return false;
  }
  return true;
       }

           if(dp[l1][l2]!=-1)
                return dp[l1][l2];
       //base case
       
       if(s[l1]==p[l2]||p[l2]=='?')
       {
           return dp[l1][l2]= f(s,p,l1-1,l2-1,dp);
       }
       else if(p[l2]=='*')
       {
           return dp[l1][l2]=f(s,p,l1-1,l2,dp)||f(s,p,l1,l2-1,dp);
  
       }
       return dp[l1][l2]=false;
   }
public:
    bool isMatch(string s, string p) {
        int l1=s.size();
        int l2=p.size();
        vector<vector<int>> dp(l1,vector<int>(l2,-1));
        return f(s,p,l1-1,l2-1,dp);
    }
};