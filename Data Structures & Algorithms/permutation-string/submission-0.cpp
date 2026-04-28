class Solution {
public:
    bool checkInclusion(string s1, string s2) { // long , short
        if (s1.length() > s2.length()) {
            return false;
        }

        unordered_map<char, int> map1; // char, how many times
        unordered_map<char, int> window; // record s2's sliding window
        for (auto c : s1) {
            map1[c]++;
        }

        int left = 0, right = 0, window_size = s1.length();

        // 2. 開始滑動視窗
        while (right < s2.length()) {
            char c = s2[right];
            window[c]++;
            right++;

            if (right - left > window_size) {
                char toRemove = s2[left];
                window[toRemove]--;
                if (window[toRemove] == 0) {
                    window.erase(toRemove);
                }

                left++;
            }

            if (window == map1) {
                return true;
            }
        }

        return false;
    }
};
