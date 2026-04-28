class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtracking(ans, "", 0, 0, n);
        return ans;
    }

    void backtracking (vector<string> &res, string cur, int open, int close, int n) {
        if (cur.size() == 2*n) {
            res.push_back(cur);
            return;
        }

        if (open < n) {
            //假設左比限制小的話
            backtracking(res, cur+"(", open+1, close, n);
        }

        if (close < open) {
            backtracking(res, cur+")", open, close+1, n);
        }
    }
};
