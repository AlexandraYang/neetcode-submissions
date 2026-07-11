class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        // step 1: find all treasure 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        //習慣一下 BFS跑方向不能像DFS依樣四個function 
        vector<pair<int, int>> dirs = {
            {1,0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        //step2: multi-src BFS 
        while(!q.empty()) {
            pair <int, int> cur = q.front();
            int r = cur.first;
            int c = cur.second;
            q.pop();

            //四個方向 要用for loop!  
            for (int i = 0; i < dirs.size() ; ++i) {
                int nr = r+dirs[i].first;
                int nc = c + dirs[i].second;

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != INT_MAX) {
                    continue;
                }

                grid[nr][nc] = grid[r][c] +1;

                q.push({nr, nc});
            }
        }
    }
};
