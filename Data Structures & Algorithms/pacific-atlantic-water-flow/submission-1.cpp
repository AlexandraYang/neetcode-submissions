class Solution {
private:
    int ROWS, COLS;
    bool pacific, atlantic;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<int>>& heights, int i, int j, int preHeight) {
        if (i < 0 || j < 0) {
            pacific = true;
            return;
        }

        if (i >= heights.size() || j >= heights[0].size()) {
            atlantic = true;
            return;
        }

        if (heights[i][j] > preHeight) {
            return; //我當前若是比前一個高 水流不了
        }

        if (heights[i][j] == INT_MAX) {
            return;
        }

        int tmp = heights[i][j];
        heights[i][j] = INT_MAX; //代表走過
        for (auto& d : dir) {
            dfs(heights, i + d[0], j + d[1], tmp);
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
        vector<vector<int>> ans;

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                //每格DFS前要重置
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
