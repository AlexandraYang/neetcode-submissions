class Solution {
private:
    // int cnt = 0;
    int helper(string s, int left, int right) {
        int cnt = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            cnt++;
            left--;
            right++;
        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        if (s.empty()) {
            return 0;
        }

        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            ans += helper(s, i, i);
            ans += helper(s, i, i+1);
        }
        
        return ans;

    }
};
