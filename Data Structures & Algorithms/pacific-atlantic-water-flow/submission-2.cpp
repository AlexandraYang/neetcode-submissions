class Solution {
private:
    int ROWS, COLS;
    vector<vector<int>> ans;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool pacific, atlantic;
    void dfs(vector<vector<int>>& heights, int i, int j, int preHeights) {
        if (i < 0 || j < 0) {
            pacific = true;
            return;
        }

        if (i >= heights.size() || j >= heights[0].size()) {
            atlantic = true;
            return;
        }

        if (heights[i][j] > preHeights) { //當前高度>前一個高度  ==> 水不能往上流
            return;
        }

        int tmp = heights[i][j];
        heights[i][j] = INT_MAX;
        for (int k =0; k < 4; ++k) {
            dfs(heights, i+dir[k][0], j+dir[k][1], tmp); //上下左右
            if (pacific && atlantic) {
                break;
            }
        }

        heights[i][j] = tmp;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();

        for (int i = 0; i < ROWS; ++i) {
            for (int j =0; j < COLS; ++j) {
                pacific = false;
                atlantic = false;
                dfs(heights, i, j, INT_MAX);
                if (pacific && atlantic) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
