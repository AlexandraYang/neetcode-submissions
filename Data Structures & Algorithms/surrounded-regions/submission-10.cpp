class Solution {
private: 
    void dfs(int r, int c, vector<vector<char>>& board) {
        if (r < 0 || c < 0 || r > board.size() || c > board[0].size() || board[r][c] != 'O') {
            return;
        }

        if (board[r][c] == 'O') {
            board[r][c] = '#';
        }

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < dirs.size(); ++i) {
            int nr = r + dirs[i].first;
            int nc = c + dirs[i].second;

            if (nr < 0 || nc < 0 || nr >= board.size() || nc >= board[0].size() || board[nr][nc] != 'O') {
                continue;
            }

            dfs(nr, nc, board);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        //從邊界的O 開始找  把他跟鄰居 都標註成 # 
        //左直  col = 0, r = delta
        for (int r = 0; r < m; ++r) {
            dfs(r, 0, board);
        }

        //右直 
        // col = n-1
        for (int r = 0; r < m; ++r) {
            dfs(r, n-1, board);
        }

        //上橫 
        // r = 0, c = delta 
        for (int c = 0; c < n; ++c) {
            dfs(0, c, board);
        }

        //下橫 
        // r = m -1, c = delta 
        for (int c = 0; c < n; ++c) {
            dfs(m-1, c, board);
        }

        //把最後 剩下的O 都標X 
         //把最後# 都標成 O 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n ; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
       
    }
};
