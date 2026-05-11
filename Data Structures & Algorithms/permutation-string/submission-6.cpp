class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> s1_window(26, 0);
        vector<int> window(26, 0);

       
        for (int i = 0; i < s1.size(); ++i) {
            s1_window[s1[i] - 'a']++;
        }

        int l = 0;
        for (int r = 0; r <s2.size(); ++r) {
            window[s2[r]-'a']++;

            if (r - l + 1 > s1.size()) {
                window[s2[l] - 'a']--;

                l++;
            }

            if (window == s1_window) {
                return true;
            }
        }

        return false;
    }
};
