
class Solution {
private: 
    queue<pair<int, int>> q;
    int mins = 0;

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            //要一層一層 
            int sz = q.size(); 
            while (sz--) {
                pair<int, int> cur = q.front(); q.pop();
                int x = cur.first;
                int y = cur.second;

                for (int i = 0; i < dirs.size(); ++i) {
                    int nr = dirs[i].first + x;
                    int nc = dirs[i].second + y;

                    //這裡我也糾結到底指filter grid[i][j] = 1
                    if (nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] != 1) { 
                        continue; 
                    }

                    if (grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        // 只有新感染的 orange 才 push!!
                        q.push({nr, nc});
                    }
                }
            }
            

            mins++;
            
        }

        //[Case 1]: 檢查最後是否還有 fresh orange
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        // [Case 2]: 這個想法在有腐爛橘子的情況下 
        // 假設一開始queue 有一個rotten, while loop 跑一次後 mins++ 
        //但其實沒有花時間 
        return mins == 0 ? 0:mins-1 ;
    }
};
