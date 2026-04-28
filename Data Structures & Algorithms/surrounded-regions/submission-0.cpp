class Solution {
private:
    int COL, ROW;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || c< 0 || r >= ROW || c >= COL) {
            return;
        }

        if (board[r][c] != 'O') {
            //從四邊出去 發現不是'O'的話 return
            return;
        }

        board[r][c] = 'E';

        for (auto &d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            dfs(board, nr, nc);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        // *** 從邊界去找'O', 只要由邊界連過去的必為不會被包圍的

        if (board.empty()) {
            return;
        }

        ROW = board.size();
        COL = board[0].size();

        for (int c = 0; c < COL; ++c) {
            //上邊
            dfs(board, 0, c);

            //下邊
            dfs(board, ROW - 1, c);
        }

        for (int r = 0; r < ROW; ++r) {
            //左邊
            dfs(board, r, 0); 

            //右邊
            dfs(board, r, COL-1);
        }

        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (board[i][j] == 'E') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
