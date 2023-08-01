class Solution {
     vector<vector<int>> ans;
    void f(int ind,int n, int k,vector<int> &digit,vector<int>&temp)
    {
        
        if(temp.size()==k)
          {ans.push_back(temp);  return ;}
        
        for(int i=ind;i<digit.size();i++)
        {
            temp.push_back(digit[i]);
            f(i+1,n,k,digit,temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> digit;
        
        for(int i=1;i<=n;i++)
            digit.push_back(i);
        
       
         vector<int> temp;
        f(0,n,k,digit,temp);
    
        return ans;
    }
};