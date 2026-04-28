class Solution {
private:
    void dfs(vector<string>& ans, string& digits, unordered_map <int, string> &mp, int start, string & tmp) {
        if (start == digits.size()) {
            ans.push_back(tmp);
            return;
        }

        for (char ch: mp[digits[start]]) {
            tmp.push_back(ch);
            dfs(ans, digits, mp, start+1, tmp);
            tmp.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string tmp;
        if (digits.empty()) {
            return ans;
        }
        unordered_map <int, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        //我卡關在要怎麼任意組合
        dfs(ans, digits, mp, 0, tmp); // ans, src, map, start_idx

        return ans;
    }
};
