class Solution {
private: 
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return 0;
        }

        if (grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;

        return 1 + dfs(i+1, j, grid) + 
                dfs(i-1, j, grid) +
                dfs(i, j+1, grid) +
                dfs(i, j-1, grid);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int max_num = 0;
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cnt = dfs(i, j, grid);

                max_num = max(max_num, cnt);
            }
        }

        return max_num;
    }
};
