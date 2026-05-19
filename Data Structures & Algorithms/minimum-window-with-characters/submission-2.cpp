class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        vector<int> windows(128, 0);
        string ans;

        // count t's freq
        for (int i = 0; i < t.size(); ++i) {
            need[t[i] - 'A']++;
        }

        int needCnt = 0;
        for (int x: need) {
            if (x > 0) {
                needCnt++;
            }
        }

        int have = 0;
        int minLen = INT_MAX;
        int l = 0;

        int start = 0;
        for (int r = 0; r < s.size(); ++r) {
            int c = s[r] - 'A';

            windows[c]++;

            if (windows[c] == need[c]) {
                have ++;
            }


            while(have == needCnt) {
                if (r - l +1 < minLen) {
                    minLen = r - l +1;
                    start = l;
                }

                int leftChar = s[l] - 'A';
                windows[leftChar]--;

                if (windows[leftChar] < need[leftChar]) {
                    have --;
                }

                l++;
            }
        }

        if(minLen == INT_MAX) {
            return "";
        }
        
        return s.substr(start, minLen);
    }
};
