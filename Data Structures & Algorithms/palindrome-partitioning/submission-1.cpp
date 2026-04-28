class Solution {
private:
    bool isPalindrome(string s, int l, int r) {
        while(l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }

        return true;
    }

    void dfs(vector<vector<string>>& ans, vector<string>& seg, string s, int start) {
        if (start == s.size()) {
            // comes to end
            ans.push_back(seg);
            return;
        }
        
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                seg.push_back(s.substr(start, i-start +1));
                dfs(ans, seg, s, i+1); // 從下一個字元開始
                seg.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> seg;

        dfs(ans, seg, s, 0);

        return ans;

    }
};
