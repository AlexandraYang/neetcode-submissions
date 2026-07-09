class Solution {
private: 
    int ans = 0;
    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
            return 0;
        }

        int cur = 1;
        if (grid[i][j] == 1) {
            grid[i][j] = 0;

            
        }

        cur += dfs(i+1, j, m, n, grid);
        cur += dfs(i-1, j, m, n, grid);
        cur += dfs(i, j+1, m, n, grid);
        cur += dfs(i, j-1, m, n, grid);

        //為什麼 dfs 要 return cur？
        //每一層 dfs 都是在跟它的小孩要「面積」
        return cur;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(i, j, m,n,grid));

                }   
                
            }
        }

        return ans;
    }
};
