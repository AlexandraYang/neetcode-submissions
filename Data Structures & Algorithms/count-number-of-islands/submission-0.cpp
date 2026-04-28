class Solution {
private:
    int cnt;
    void dfs(vector<vector<char>>& grid, int r, int c) {
        // 越界直接返回
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) {
            return;
        }

        //非陸地或已經訪問過 則直接return
        if (grid[r][c] == '0') {
            return;
        }

        // 標記為已訪問 (用 '0' 把陸地沉掉)
        grid[r][c] = '0';

        //往四面八方擴散
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                //當在這裡遇到一塊陸地時 代表發現一個新島嶼
                if (grid[i][j] == '1') {
                    cnt++; // 需要在這裡加一 因為是一個新的島的起點
                    dfs(grid, i, j); // 然後用DFS把整個島淹掉(標成 0 代表訪問過)
                }
            }
        }
        return cnt;
    }
};
