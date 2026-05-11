class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> s1_windows(26, 0);
        vector<int> windows(26, 0);

        for (int l = 0; l < s1.size(); ++l) {
            s1_windows[s1[l] -'a']++;
        }
        int l = 0;
        for (int r = 0; r < s2.size(); ++r) {

            windows[s2[r]-'a']++;

            if ((r - l + 1 ) > s1.size()) {
                windows[s2[l]-'a'] --;
                l++;
            }

            if (windows == s1_windows) {
                return true;
            }

        
        }
        return false;
    }
};
