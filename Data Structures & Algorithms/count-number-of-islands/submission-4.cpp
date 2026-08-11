class Solution {
private: 
    void dfs(vector<vector<char>> & grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {
            return;
        }

        //走過的不要再走
        if (grid[x][y] == '0') {
            return;
        }

        //把走過的都淹過
        grid[x][y] = '0';

        //上下左右
        dfs(grid, x+1, y);
        dfs(grid, x, y+1);
        dfs(grid, x-1, y);
        dfs(grid, x, y-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i<m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ans ++;
                    dfs(grid, i, j);
                }
            }
        }

        return ans;
    }
};
