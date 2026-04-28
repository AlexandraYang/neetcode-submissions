class Solution {
public:
    int characterReplacement(string s, int k) {
        vector <int> count(26, 0);  // 記錄每個字元的出現次數
        int max_count =0; // 當前視窗內最多出現的字元次數
        int l = 0;
        int max_len = 0;

        for (int r = 0; r < s.size(); ++r) {
            count[s[r] - 'A']++;
            max_count = max(max_count, count[s[r] - 'A']);

            // 如果替換次數超過 k，視窗不合法，要縮小
            while ((r-l+1) - max_count > k) {
                count[s[l] - 'A'] --;
                l++;
            }

            max_len = max(max_len, r-l+1);
        }

        return max_len;
    }
};
