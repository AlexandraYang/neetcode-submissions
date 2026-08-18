class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> src;
        int fresh = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) {
                    src.push({i,j});
                }

                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int mins = 0;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!src.empty() && fresh > 0) {
            int sz = src.size();

            
            while(sz--) {
                pair<int, int> cur = src.front();
                src.pop();

                int x = cur.first;
                int y = cur.second;
                for (int d = 0; d < dirs.size(); ++d) {
                    int next_x = dirs[d][0] + x;
                    int next_y = dirs[d][1] + y;

                    if (next_x < 0 || next_y < 0 || next_x >= grid.size() || next_y >= grid[0].size()) {
                        continue;
                    }

                    if (grid[next_x][next_y] == 1) {
                        grid[next_x][next_y] = 2;
                        fresh--;
                        src.push({next_x, next_y});
                    }
                }
            }
            mins++;
        }

        if (fresh > 0) {
            return -1;
        }

        return mins;

    }
};
