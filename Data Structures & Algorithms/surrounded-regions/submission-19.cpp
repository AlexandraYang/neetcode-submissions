class Solution {
private: 
    void dfs(int i, int j, vector<vector<char>>& board) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O') {
            return;
        }

        if (board[i][j] == 'O') {
            board[i][j] = '#';
        }
        

        dfs(i+1, j, board);
        dfs(i-1, j, board);
        dfs(i, j+1, board);
        dfs(i, j-1, board);
    }
public:
    void solve(vector<vector<char>>& board) {
        //先從boarder開始找 因為摸到邊的 O 其實不會變 O 
        //還有他的鄰居也要都標為 # 

        int m = board.size();
        int n = board[0].size();
        
        //上row , r= 0, c = delta 
        for (int c = 0; c < n; ++c) {
            dfs(0, c, board);
        }

        //下row , r = n-1, c = delta 
        for (int c = 0; c < n; ++c) {
            dfs(m-1, c, board);
        }


        //左col. r = delta, c = 0
        for (int r = 0; r < m; ++r) {
            dfs(r, 0, board);
        } 

        //右col , r = delta, c = n-1
        for (int r = 0; r < m; ++r) {
            dfs(r, n-1, board);
        }

        //把所有O 改成 X 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } 
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } 
            }
        }


    }
};
