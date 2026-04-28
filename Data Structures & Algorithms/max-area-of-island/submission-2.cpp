class Solution {
private:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<int>>& grid, int i, int j, int& cnt) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }

        if (grid[i][j] != 1) {
            return;
        }
        
        grid[i][j] = 2;
        cnt ++;
        for (auto &d: dirs) {
            int nr = i + d[0];
            int nc = j + d[1];

            dfs(grid, nr, nc, cnt);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int max_num = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j =0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    int cnt = 0; //每次都需要重置!!
                    dfs(grid, i, j, cnt);
                    max_num = max(max_num, cnt);
                }
            }
        }
        return max_num;
    }
};
