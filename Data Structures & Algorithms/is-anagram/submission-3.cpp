class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int cnt[26] = {0};
        for (int i = 0; i <= s.size() - 1; ++i) {
            cnt[s[i] - 'a'] ++;
            cnt[t[i] - 'a'] --;
        }

        for (int i = 0; i < size(cnt) ; ++i) {
            if (cnt[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
