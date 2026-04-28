class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right =0;
        unordered_map <char, int> window_cnt;
        int formed =0;

        unordered_map <char, int> t_cnt;
        for (auto c: t) {
            t_cnt[c]++;
        }

        int required = t_cnt.size();
        int min_len = INT_MAX, min_start = 0;

        while (right < s.size()) {
            char c = s[right];
            window_cnt[c]++;

            if (t_cnt.count(c) && window_cnt[c] == t_cnt[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                if (right -left + 1 < min_len) {
                    min_len = right-left +1;
                    min_start = left;
                }

                char lchar = s[left];
                window_cnt[lchar]--;

                if (t_cnt.count(lchar) && window_cnt[lchar] < t_cnt[lchar]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};
