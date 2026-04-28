class Solution {
private:
    int COL, ROW;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs (vector<vector<char>>& board, int i, int j) {
        //超過邊界直接return
        if (i < 0 || j < 0 || i >= ROW || j >= COL) {
            return;
        }

        //若不是圈的話 也不要走 要return
        if (board[i][j] != 'O') {
            return;
        }

        //走過的要return
        board[i][j] = 'E';

        //上下左右走
        for (auto &d : dirs) {
            int nr = i + d[0];
            int nc = j + d[1];

            dfs(board, nr, nc);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        // *** 從邊界連過去的 O 必不會被包圍

        if (board.empty()) {
            return;
        }

        ROW = board.size();
        COL = board[0].size();

        // 從四邊去找
        for (int r = 0; r < ROW; ++r) {//左右
            dfs(board, r, 0);
            dfs(board, r, COL - 1);
        }

        for (int c = 0; c < COL; ++c) {//左右
            dfs(board, 0, c);
            dfs(board, ROW -1, c);
        }

        // replace E -> O
        // replace O -> X
        for (int i =0; i < ROW; ++i) {
            for (int j =0; j < COL; ++j) {
                if (board[i][j] == 'E') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
