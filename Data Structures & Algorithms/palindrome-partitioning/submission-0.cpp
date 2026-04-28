class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> seg;

        dfs(s, seg, 0, ans);

        return ans;
    }

private:
    void dfs(string s, vector<string>& seg, int start, vector<vector<string>>& ans) {
        if (start == s.size()) {
            ans.push_back(seg);
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                seg.push_back(s.substr(start, i - start + 1));

                dfs(s, seg, i+1, ans);

                seg.pop_back();
            }
        }

    }

    bool isPalindrome(const string & s, int l, int r) {
        while(l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};
