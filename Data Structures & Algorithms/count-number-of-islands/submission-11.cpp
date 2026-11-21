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
        for  (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (dfs(i, j, grid) == 1) {
                    //DFS check all directions and get back to 1'st call stack
                    nums++;
                }
            }
        }

        return nums;

    }
};
