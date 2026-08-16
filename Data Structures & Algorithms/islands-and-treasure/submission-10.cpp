class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //找出 所有寶藏起點
        queue<pair<int, int>>q;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();

            for (int n = 0; n < dirs.size(); ++n) {

                int cur_x = cur.first+dirs[n][0];
                int cur_y = cur.second+dirs[n][1];

                if (cur_x < 0 || cur_y < 0 || cur_x >= grid.size() || cur_y >= grid[0].size()) {
                    continue;
                }

                // 不是 INF：代表不能走 / 已經走過
                if (grid[cur_x][cur_y] != 2147483647 ) {
                    continue;
                }


                grid[cur_x][cur_y] = grid[cur.first][cur.second] +1;

                q.push({cur_x, cur_y});
            }
            
        }
    }
};
