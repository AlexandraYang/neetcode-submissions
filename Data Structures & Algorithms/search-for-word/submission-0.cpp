class Solution {
private:
    bool dfs(vector<vector<char>>& board, int i , int j, string word, int start) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return false;
        }
        
        if (board[i][j] != word[start]) {
            //comes to word's end
            return false;
        }

        if (start == word.size()-1) {
            return true;
        }
        
        char tmp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(board, i-1, j, word, start+1) ||
                    dfs(board, i+1, j, word, start+1) ||
                    dfs(board, i, j-1, word, start+1) ||
                    dfs(board, i, j+1, word, start+1);

        board[i][j] = tmp;

        return found;


    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<char> seg;
        for (int i =0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
