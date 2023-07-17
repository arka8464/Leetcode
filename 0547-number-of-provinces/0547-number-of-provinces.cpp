class Solution {
    void dfs(int i, vector<vector<int>>& isConnected, vector<int>& visited) {
        for (int j = 0; j < isConnected.size(); ++j) {
            if (isConnected[i][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                dfs(j, isConnected, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int provinces = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                dfs(i, isConnected, visited);
                ++provinces;
            }
        }
        return provinces;
    }
};
