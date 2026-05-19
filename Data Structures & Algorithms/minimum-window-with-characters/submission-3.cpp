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

        // 紀錄有幾種字元需要滿足 
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

            //是否達標
            if (windows[c] == need[c]) {
                have ++;
            }

            //如果需要的字元數都符合了 
            while(have == needCnt) {
                //那就開始計算s內的 符合頻率的寬度最小是多少 
                if (r - l +1 < minLen) {
                    minLen = r - l +1;
                    start = l;
                }

                // 心法: 我知道目前合法 所以開始貪心縮小
                // 這題不是： 找到一個合法 window 就結束
                // 而是： 找到 "最小" 合法 window
                // 所以： 即使現在合法 還是要繼續縮
                // 看看：能不能更小
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
