class Solution {
private:
    bool isPalindrome(string src, int l, int r) {
        while (l < r) {
            if (src[l++] != src[r--]) {
                return false;
            }
        }

        return true;
    }

    void dfs(vector<vector<string>>& ans, vector<string>& seg, int start, string& s) {
        if (start == s.size()) {
            ans.push_back(seg);
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                seg.push_back(s.substr(start, i - start + 1));
                dfs(ans, seg, i+1, s);
                seg.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        // 小function for check palindrome
        vector<vector<string>> ans;
        vector<string> seg;

        dfs(ans, seg, 0, s);

        return ans;
    }
};
