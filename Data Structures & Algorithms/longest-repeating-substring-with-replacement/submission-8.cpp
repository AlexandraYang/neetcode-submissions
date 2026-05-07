class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        vector<int> count(26, 0);
        int max_freq = 0;
        int ans = 0;
        for (int r = 0; r < s.size(); ++r) {
            count[s[r]- 'A']++;

            max_freq = max(max_freq, count[s[r] - 'A']);


            while((r-l+1) - max_freq > k) {
                count[s[l] - 'A']--;
                l++;
            }

            ans = max(ans, r -l +1);

        }

        return ans;
    }
};
