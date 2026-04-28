class Solution {
public:
    string minWindow(string s, string t) {
        int left =0, right = 0;
        unordered_map <char, int> window_cnt;
        int formed = 0;

        unordered_map<char, int> t_count;
        for (char c : t) {
            t_count[c]++;
        }

        int required = t_count.size();
        int min_len = INT_MAX, min_start = 0;

        

        while (right < s.size()) {
            char c = s[right];
            window_cnt[c]++;

            if (t_count.count(c) && window_cnt[c] == t_count[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                // 更新最小解
                if (right -left + 1 < min_len) {
                    min_len = right-left +1;
                    min_start = left;
                }

                char lchar = s[left];
                window_cnt[lchar]--;

                if (t_count.count(lchar) && window_cnt[lchar] < t_count[lchar]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};
