class Solution {
private: 
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
             // 1. boundary
             // 2. visited
            if (r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size() || visited[r][c] == true) {
                return;
            }
            
             // 1. visited
            visited[r][c] = true;

             // 2. 四個方向
            vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

             // 3. boundary
             // 4. 已拜訪
            

            
            
             // 6. dfs(next)
             for (int i = 0; i < dirs.size(); ++i) {
                
                int x = r + dirs[i].first;
                int y = c + dirs[i].second;

                if (x < 0 || y < 0 || x >= heights.size() || y >= heights[0].size()) {
                    continue;
                }
                
                // 5. height 條件
                if (heights[r][c] > heights[x][y] ) {
                    continue;
                }

                dfs(heights, visited, x, y);
             }
            
            
            

         }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row_size = heights.size();
        int col_size = heights[0].size();

        //要初始化!! 
        vector<vector<bool>> pacific_vistied(row_size, vector<bool>(col_size, false));
        vector<vector<bool>> atlantic_vistied(row_size, vector<bool>(col_size, false));

        

        vector<vector<int>> ans;

        // pacific_vistied
        for (int i = 0; i < col_size; ++i) {
            //最上row
            dfs(heights, pacific_vistied, 0, i);
        }

        // pacific_vistied
        for (int r = 0; r < row_size; ++r) {
            //最左col 
            dfs(heights, pacific_vistied, r, 0);
        }

        // atlantic_vistied
        for (int r = 0; r < row_size; ++r) {
            //最右col 
            dfs(heights, atlantic_vistied, r, col_size-1);
        }

        // atlantic_vistied
        for (int i = 0; i < col_size; ++i) {
            //最下row
            dfs(heights, atlantic_vistied, row_size-1, i);
        }

        for (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < col_size; ++j) {
                if (pacific_vistied[i][j] == true && atlantic_vistied[i][j] == true ) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
