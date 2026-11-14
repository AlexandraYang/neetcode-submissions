class Solution {
private:
    int dfs(int i, int j, vector<vector<char>>& grid) {
        //edge 
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return 0;
        }

        if (grid[i][j] == '0') {
            return 0;
        }

        grid[i][j] = '0';

        dfs(i + 1, j, grid);
        dfs(i -1 , j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);

        return 1;
    }

    //[1, 0, 1]
    //
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int nums = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (dfs(i, j, grid) == 1) {
                    nums++;
                }
            }
        }

        return nums;
    }
};
