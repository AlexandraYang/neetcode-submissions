class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);

        int l = 0;
        int max_freq = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); ++r) {
            count[s[r] - 'A']++; //計算向右擴張後 freq 到多少

            max_freq = max(max_freq, count[s[r] - 'A']); //每次擴張後 就查表一次看誰大 

            while ( (r - l +1) - max_freq > k) {
                count[s[l] - 'A']--;
                l++;
            }

            ans = max(ans, r -l +1);
        }

        return ans;
    }
};
