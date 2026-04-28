class Solution {
private:

    bool backtracking(vector<vector<char>>& board, string& word, int start, int r, int c) {
        if (start == word.size()) {
            return true;
        }

        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) {
            return false;
        }

        if (word[start] != board[r][c]) {
            return false;
        }

        char tmp = board[r][c];
        board[r][c] = '#';
        // 上下左右找
        bool found = backtracking(board, word, start + 1, r+1 , c) || 
                        backtracking(board, word, start + 1, r-1 , c) ||
                        backtracking(board, word, start + 1, r , c-1) ||
                        backtracking(board, word, start + 1, r , c+1);

        board[r][c] = tmp;
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        //此題是DFS + 回朔法
        int n = board[0].size(); // col
        int m = board.size(); // row
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; ++c) {
                if (backtracking(board, word, 0, r, c)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
