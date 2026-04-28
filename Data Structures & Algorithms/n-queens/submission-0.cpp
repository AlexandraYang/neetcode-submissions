class Solution {
private:
    vector<vector<string>> ans;
    vector<string> board;
    unordered_set <int> col;
    unordered_set <int> posDiag;
    unordered_set <int> negDiag;
    int n;

    void dfs(int r) {
        if (r == n ) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; ++c) {
            if (col.count(c) || posDiag.count(r+c) || negDiag.count(r-c)) {
                continue;
            }

            col.insert(c);
            posDiag.insert(r+c);
            negDiag.insert(r-c);
            board[r][c] = 'Q';

            dfs(r+1);

            col.erase(c);
            posDiag.erase(r+c);
            negDiag.erase(r-c);
            board[r][c] = '.';
        }
    }


public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board = vector<string> (n, string(n, '.'));

        dfs(0);

        return ans;
    }
};
