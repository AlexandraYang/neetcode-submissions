class Solution {
private:
    int ROW, COL;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs (vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited) {
        visited[i][j] = true;

        for (auto& d: dirs) {
            int nr = i + d[0];
            int nc = j + d[1];

            if (nr < 0 || nc < 0 || nr >= ROW || nc >= COL) {
                continue;
            }

            if (visited[nr][nc]) {
                continue;
            }

            // 假設海往山上流 必須是下一個比我高
            //(反向思考) 但假設沒有更高的話 那就要return
            // 代表只允許「相鄰aka下一格高度 ≥ 現在高度」的情況下繼續 DFS。
            if (heights[i][j] > heights[nr][nc]) {
                continue;
            }

            dfs(heights, nr, nc, visited);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // 我要從row col 的上下左右dfs
        // 宣告 兩個二微陣列
        ROW = heights.size();
        COL = heights[0].size();
        vector<vector<int>> ans;

        // 宣告兩個vector
        vector<vector<bool>> pacific(ROW, vector<bool>(COL, false));
        vector<vector<bool>> atlantic(ROW, vector<bool>(COL, false));

        for (int c = 0; c < COL; ++c) {
            // 上下ROW
            dfs(heights, 0, c, pacific);
            dfs(heights, ROW-1, c, atlantic);
        }

        for (int r = 0; r < ROW; ++r) {
            // 左右col
            dfs(heights, r, 0, pacific);
            dfs(heights, r, COL-1, atlantic);
        }

        for (int r = 0; r < ROW; ++r) {
            for (int c = 0; c < COL; ++c) {
                if (pacific[r][c] && atlantic[r][c]) {
                    ans.push_back({r,c});
                }
            }
        }

        return ans;
    }
};
