class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return;
        }

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q; // 紀錄座標i , j
        //把所有grid[i][j] 寶藏的推入queue
        for (int i =0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            //上下左右走 
            int dir_r[4] = {-1, 1, 0, 0};
            int dir_c[4] = {0, 0, -1, 1};
            for (int k = 0; k < 4; ++k) {
                int next_r = r + dir_r[k];
                int next_c = c + dir_c[k];

                // boundary check
                if (next_r < 0 || next_r >= m || next_c < 0 || next_c >= n) {
                    continue;
                }

                // 走過的不走
                if (grid[next_r][next_c] != INT_MAX) {
                    continue;
                }

                //真的走 ，走過要加+1, 擴散的格子 是 原來格子的 +1
                grid[next_r][next_c] = grid[r][c] + 1;

                //繼續擴散
                q.push({next_r, next_c});
            }
        }
    }
};
