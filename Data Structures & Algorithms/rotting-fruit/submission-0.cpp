
class Solution {
private:
    int min = 0;
    int fresh = 0;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return -1;
        }

        //多點BFS SRC
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        while(!q.empty()) {
            int size = q.size(); //本分鐘要處理的橘子數量
            bool rotted = false; // 本輪是否真的有新的橘子腐爛
            for (int i = 0; i < size; ++i) { //處理此ㄈ中所有腐爛的橘子
                auto [r, c] = q.front();
                q.pop();

                int dir_r[4] = {-1, 1, 0, 0};
                int dir_c[4] = {0, 0 , -1, 1};

                // 擴散四周
                for (int k = 0; k < 4; ++k) {
                    int next_r = r + dir_r[k];
                    int next_c = c + dir_c[k];

                    if (next_r < 0 || next_r >= m || next_c < 0 || next_c >= n) {
                        continue;
                    }

                    if (grid[next_r][next_c] != 1) {
                        //不新鮮我也忽略
                        continue;
                    }

                    // rotten水果
                    grid[next_r][next_c] = 2;
                    q.push({next_r, next_c});

                    fresh--;   // 更新剩餘新鮮橘子
                    rotted = true;
                }
            }
           
           if (rotted) min++; 
            
        }

        return fresh == 0 ? min : -1;

    }
};

















