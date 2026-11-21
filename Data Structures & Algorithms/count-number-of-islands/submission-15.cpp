class Solution {
private:
    int dfs(int i_idx, int j_idx, vector<vector<char>>& grid) {
        // edge 
        if (i_idx < 0 || j_idx < 0 || i_idx >= grid.size() || j_idx >= grid[0].size()) {
            return 0;
        }

        if (grid[i_idx][j_idx] == '0') {
            // water or visited !
            return 0;
        }

        grid[i_idx][j_idx] = '0';

        dfs(i_idx + 1, j_idx, grid);
        dfs(i_idx -1, j_idx, grid);
        dfs(i_idx, j_idx + 1, grid);
        dfs(i_idx, j_idx -1, grid);

        return 1;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        // DFS
        int row = grid.size();
        int col = grid[0].size();
        int nums = 0;

        queue<pair<int, int>> q;

        vector<pair<int, int>> dirs = {{0, 1}, {1,0}, {-1, 0}, {0, -1}};

        for  (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {

                //if this cell is an unvisited '1':
                if (grid[i][j] == '1') {
                    //count it as a new island
                    nums++;
                 
                    grid[i][j] = '0';
                    q.push({i,j});

                    while (q.empty() != true) {
                    
                        pair<int, int> tmp = q.front();
                        q.pop();

                        int i_temp = tmp.first;
                        int j_temp = tmp.second;
                        if (i_temp < 0 || i_temp >= grid.size() || j_temp < 0 || j_temp >= grid[0].size()) {
                            break;
                        }

                    

                        for (int dir = 0; dir < dirs.size(); ++dir) {
                            int final_i = i_temp+dirs[dir].first;
                            int final_j = j_temp+dirs[dir].second;
                            // //check twice ?
                            if (final_i < 0 || final_i >= grid.size() || final_j < 0 || final_j >= grid[0].size() || grid[final_i][final_j] == '0') {
                                continue;
                            }
                            // mark visited whenever it pushed
                            //
                            grid[final_i][final_j] = '0';
                            q.push({final_i, final_j});
                        }
                    
                    }   
                }
            }
        }

        return nums;

    }
};
