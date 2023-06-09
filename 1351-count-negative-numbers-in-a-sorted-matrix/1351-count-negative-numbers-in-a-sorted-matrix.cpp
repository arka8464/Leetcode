class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
      int ans=0;
       for(int i=0;i<grid.size();i++)
       {
           int temp;
           temp=upper_bound(grid[i].rbegin(),grid[i].rend(),-1)-grid[i].rbegin();
           cout<<temp<<endl;
           ans+=temp;
               
       }
        return ans;
    }
};