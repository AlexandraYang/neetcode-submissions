class Solution {
private:
    bool dfs(int i, int j, int idx, string word, vector<vector<char>>& board) {
        if (word.size() == idx) {
            return true;
        }

        // out of boundary
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return false;
        }
        
        // word is not matched
        if (word[idx] != board[i][j]) {
            return false;
        } 

        char tmp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(i + 1, j , idx+1, word, board) ||
                    dfs(i -1, j , idx+1, word, board) ||
                    dfs(i , j + 1, idx+1, word, board) ||
                    dfs(i , j -1 , idx+1, word, board);
        
        board[i][j] = tmp;
        return found;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        // for loop 然後每一個格字都跑dfs
        // 每次dfs進去後的start idx 都跟word比對 假設沒符合就不繼續dfs

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(i, j , 0,  word, board)) {
                    return true;
                }
            }
        }

        return false;
    }
};
