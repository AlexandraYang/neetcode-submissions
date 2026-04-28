class Solution {
private:
    void dfs(vector<vector<int>>& heights, int i, int j, int preHeight) {
        if (i < 0 || j < 0) {
            pacific = true;
            return;
        }

        if (i >= ROWS || j >= COLS) {
            atlantic = true;
            return;
        }

        if (heights[i][j] > preHeight) {
            return;
        }

        // backtracking
        int tmp = heights[i][j];
        heights[i][j] = INT_MAX;
        for (int k = 0; k < 4; ++k) {
            int next_r = i + dir[k][0];
            int next_c = j + dir[k][1];

            dfs(heights, next_r, next_c, tmp);
            if (pacific && atlantic) {
                break;
            }
        }

        heights[i][j] = tmp;
    }
public:
    int ROWS, COLS;
    bool pacific, atlantic;

    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < ROWS; ++i) {
            for (int j =0; j < COLS; ++j) {
                pacific = false;     // ← 這兩行要重置！
                atlantic = false;
                //INT_MAX 其實是preHeight, 當前val 需要小於
                dfs(heights, i, j, INT_MAX);
                if (pacific && atlantic) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;

    }
};
