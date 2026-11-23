class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int nums = 0;
        int cur_num = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    cur_num++;
                   
                    q.push({i, j});
                    grid[i][j] = 0;

                     while (q.empty() != true) {
                        pair<int, int> tmp = q.front();
                        q.pop();
                        for (int d = 0; d < dirs.size(); ++d) {
                            int i_idx = tmp.first + dirs[d].first;
                            int j_idx = tmp.second + dirs[d].second;
                            
                            if (i_idx < 0 || j_idx < 0 || i_idx >= grid.size() || j_idx >= grid[0].size()) {
                                continue;
                            }
                            if (grid[i_idx][j_idx] == 0) {
                                continue;
                            }

                            q.push({i_idx, j_idx});
                            grid[i_idx][j_idx] =0;
                            cur_num++;
                           
                        }
                     }
                      nums = max(nums, cur_num);
                      cur_num = 0;

                }

               
            }
        }

        return nums;





    }
};
