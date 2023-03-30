class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1&&m==1&&grid[0][0]==0)
            return 1;
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        
        vector<vector<int>> dis(grid.size(), vector<int>(grid[0].size(), 1e8));
        dis[0][0] = 0;
        queue<pair<pair<int, int>, int>> pq; //{row,col}, wt
        pq.push({{0, 0}, 1});

        while(!pq.empty()) {
            auto frontRow = pq.front().first.first;
            auto frontCol = pq.front().first.second;
            auto frontDis = pq.front().second;
            pq.pop();

            for(int row = -1; row <= 1; row++) {
                for(int col = -1; col <= 1; col++) {
                    int newRow = frontRow + row;
                    int newCol = frontCol + col;

                    if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size()
                      && frontDis + 1 < dis[newRow][newCol] && grid[newRow][newCol] == 0) {
                        dis[newRow][newCol] = frontDis + 1;
                        if(newRow == grid.size() - 1 && newCol == grid[0].size() - 1)
                            return dis[newRow][newCol];
                        pq.push({{newRow, newCol}, frontDis + 1});
                    }
                }
            }
        }
        return -1;
    }
};
