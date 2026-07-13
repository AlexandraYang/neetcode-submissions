class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                } 
            }
        }

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            pair<int, int> cur = q.front(); 
            q.pop();

            int x = cur.first;
            int y = cur.second;

            for (int i = 0; i < dirs.size(); ++i) {
                int nr = x + dirs[i].first;
                int nc = y + dirs[i].second;


                if (nr >= m || nc>= n || nr < 0 || nc < 0 || grid[nr][nc] == -1) {
                    continue;
                }
                if (grid[nr][nc] == INT_MAX) {
                    grid[nr][nc] = grid[x][y] +1;
                    q.push({nr,nc});
                }
                
            }
        }
    }
};
