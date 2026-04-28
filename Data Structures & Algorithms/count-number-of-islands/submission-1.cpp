class Solution {
private:
    int cnt;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i <0 || j <0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }

        if (grid[i][j] != '1') {
            return;
        }

        char tmp = grid[i][j];
        grid[i][j] = '#';
        for (auto& d : dirs) {
            int nr = i + d[0];
            int nc = j + d[1];

            dfs(grid, nr, nc);
        }
        

    }

public:
    int numIslands(vector<vector<char>>& grid) {
        cnt = 0;
        for (int i =0; i < grid.size(); ++i) {
            for (int j =0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
                
            }
        }   
        return cnt;
    }
};
