class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cnt=0;
        unordered_map<int,int>m;
        for(auto it:arr )
            m[it]++;
        
        for(int i=1;i<=arr[arr.size()-1];i++)
        {
          if(m.find(i)==m.end())
              cnt++;
            if(cnt==k)
                return i;
        }
        
        return arr[arr.size()-1]+(k-cnt) ;
    }
};