class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);//因為是大寫
        vector<int> window(128, 0);

        for (int i = 0; i < t.size(); ++i) {
            need[t[i] - 'A']++;
        }

        int needCnt = 0;//需要達標的種類數
        for (int x: need) {
            //t 裡有幾種「不同字元」是必須出現的
            if (x>0) {
                needCnt++;
            }
        }
        int have = 0; //已經達標的種類數

        int l =0;
        int start = 0;
        int minLen = INT_MAX;

        for (int r = 0; r < s.size(); ++r) {
            int c = s[r] - 'A';
            window[c]++;

            //我要 match 每一種字元是否達標
            if (window[c] == need[c]) {
                have++;
            }

            //合法的情況下開始shrink
            while(have == needCnt) {
                //更新答案 
                if (r - l +1 < minLen) {
                    minLen = r -l +1;
                    start =l ;
                }

                int leftChar = s[l] - 'A';

                window[leftChar] --;

                if (window[leftChar] < need[leftChar]) {
                    have--;
                }

                l++;
            }
            
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};
