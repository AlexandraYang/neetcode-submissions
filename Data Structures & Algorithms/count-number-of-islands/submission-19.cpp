class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int nums = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    nums++;
                    q.push({i, j});
                    grid[i][j] = '0'; 

                    while(q.empty()!=true) {
                        
                        pair<int, int> tmp = q.front();
                        q.pop();

                        for (int d = 0; d < dirs.size(); ++d) {
                            int i_idx = tmp.first + dirs[d].first;
                            int j_idx = tmp.second + dirs[d].second;



                            if (i_idx < 0 || j_idx < 0 || i_idx >= grid.size() || j_idx >= grid[0].size()) {
                                continue;
                            } 

                            if (grid[i_idx][j_idx] == '0') {
                                continue;
                            }

                            q.push({i_idx, j_idx});
                            grid[i_idx][j_idx] = '0';
                        }
                    }
                }
            }
        }

        return nums;
    }
};
