class Solution {
private:
    int max_cnt = 0;

    void dfs(vector<vector<int>>& grid, int i, int j, int& cur_cnt) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }
        
        if (grid[i][j] == 0) {
            return;
        }

        grid[i][j] = 0;
        cur_cnt++;

        dfs(grid, i+1, j, cur_cnt);
        dfs(grid, i-1, j, cur_cnt);
        dfs(grid, i, j+1, cur_cnt);
        dfs(grid, i, j-1, cur_cnt);

    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        max_cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j =0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {                   
                    int cur_cnt = 0;
                    dfs(grid, i, j, cur_cnt);
                    max_cnt = max(max_cnt, cur_cnt);
                } 
            }
        }

        return max_cnt;
    }
};
