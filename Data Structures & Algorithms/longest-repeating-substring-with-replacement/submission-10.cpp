class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        vector<int> count(26, 0);
        int max_freq = 0;
        int ans = 0;
        for (int r = 0; r < s.size(); ++r) {
            // 擴張r , 且更新freq arr
            count[s[r] - 'A']++;
            max_freq = max(max_freq, count[s[r] - 'A']);
            while((r-l + 1) - max_freq  > k) {
                //縮左邊 

                count[s[l] - 'A']--;
                l ++;
            }

            ans = max(r-l +1, ans);

        }

        return ans;
    }
};
