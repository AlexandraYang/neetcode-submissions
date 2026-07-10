class Solution {
private:
    int max_val = 0;
    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
            return 0;
        }
        
        grid[i][j] = 0;

        return 1 + dfs(i + 1, j, m, n, grid) + 
                    dfs(i - 1, j, m, n, grid) + 
                    dfs(i, j+ 1, m, n, grid) + 
                    dfs(i, j-1, m, n, grid); 


    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        for (int i =0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                max_val = max(max_val, dfs(i, j, m,n, grid));
            }
        }

        return max_val;
    }
};
