class Solution {
private:
    vector<string> ans;
public:
    void backtracking (string cur, int left, int right, int n) {
        if (left == n && right == n) {
            ans.push_back(cur);
            return;
        }
        
        if (left <n) {
            backtracking(cur + "(", left + 1, right, n);
        }

        if (right < left) {
            backtracking(cur + ")", left , right+ 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur;
        backtracking(cur, 0, 0 , n);
        return ans;
    }
};
