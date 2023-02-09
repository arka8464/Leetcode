class Solution {
//     int f( int i,int j,string &s1,string &s2, vector<vector<int>>&dp)
//     {
//        if(i<0)return 0;
//        if(j<0)return 1;
//        if(dp[i][j]!=-1) return dp[i][j];
        
//         if(s1[i]==s2[j])
//         {
//             int take=f(i-1,j-1,s1,s2,dp); //take s1 & s2
//             int nottake=f(i-1,j,s1,s2,dp);//take s1 but !s2
//             return dp[i][j]=take+nottake;
                
//         }
//         else
//         return dp[i][j]=f(i-1,j,s1,s2,dp);//not matching hence reduing 
//     }
    int countUtil(string& s1, string& s2, int ind1, int ind2,vector<vector<int>>& dp){
    if(ind2<0)
        return 1;
    if(ind1<0)
        return 0;
    
    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
    
    if(s1[ind1]==s2[ind2]){
        int leaveOne = countUtil(s1,s2,ind1-1,ind2-1,dp);
        int stay = countUtil(s1,s2,ind1-1,ind2,dp);
        
        return dp[ind1][ind2] = (leaveOne + stay);
    }
    
    else{
        return dp[ind1][ind2] = countUtil(s1,s2,ind1-1,ind2,dp);
    }
}
public:
    int numDistinct(string s1, string s2) {
        int i=s1.size();
        int j=s2.size();
        vector<vector<int>>dp(i,vector<int>(j,-1));
        return countUtil(s1,s2,i-1,j-1,dp);
    }
};