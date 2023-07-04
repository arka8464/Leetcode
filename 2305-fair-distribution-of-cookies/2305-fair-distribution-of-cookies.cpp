class Solution {
    void f(int ind,vector<int>& cookies, int k)
    {
       if(ind == cookies.size())
        {
            int maxi=0;
            for (int i = 0; i < k; i++) 
            {
                maxi = max(maxi, cnt[i]);
            }
            ans = min(ans, maxi);
            return;
        }
        
        for(int i=0;i<k;i++)
        {
             cnt[i] += cookies[ind];
            f(ind + 1, cookies, k);
            cnt[i] -= cookies[ind];
            if (cnt[i] == 0) {
                break;
            }
        }
    }
public:
    int ans;
    vector<int>cnt;
    int distributeCookies(vector<int>& cookies, int k) {
        ans=INT_MAX;
        cnt.resize(k);
        f(0,cookies,k);//function to backtrack 
    return ans;
    }
};