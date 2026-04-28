class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set <char>> col(9);
        vector<unordered_set <char>> row(9);
        vector<unordered_set <char>> boxed(9);

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                int box_num = (i/3) * 3 + j/3;

                if (board[i][j] == '.') {
                    continue;
                }

                if (col[i].count(board[i][j]) || row[j].count(board[i][j]) || boxed[box_num].count(board[i][j])) {
                    return false;
                }

                col[i].insert(board[i][j]);
                row[j].insert(board[i][j]);
                boxed[box_num].insert(board[i][j]);
            }

        }
        return true;
    }
};
