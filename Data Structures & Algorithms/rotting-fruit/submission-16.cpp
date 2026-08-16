class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    //把rotten fruit 放入
                    q.push({i, j});
                }

                //phase 2:
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }   

        int mins = 0;

        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty() && fresh > 0) {
            int sz = q.size();

            //一整層，一分鐘
            for (int len = 0; len < sz; ++ len) {
                pair<int, int> cur = q.front();
                q.pop();
                int x = cur.first;
                int y = cur.second;

                for (int n = 0; n < dirs.size(); ++n) {
                    int next_x = x + dirs[n][0];
                    int next_y = y + dirs[n][1];
                    if (next_x < 0 || next_y < 0 || next_x >= grid.size() || next_y >= grid[0].size() || grid[next_x][next_y] == 0) {
                        continue;
                    }

                    if (grid[next_x][next_y] == 1) {
                        grid[next_x][next_y] = 2;

                        //真的被感染的話 fresh--
                        fresh--;
                        q.push({next_x, next_y});
                    }   
                }
            }
            mins++;
        }

        //最後 fresh 還是存在 那就是rotten 不了全部
        if (fresh > 0) {
            return -1;
        }

        return mins;

    }
};
