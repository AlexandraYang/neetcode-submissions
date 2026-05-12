class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //重點是 s2 是否有包含 s1 任意組合 
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> s1_windows(26, 0);
        vector<int> windows(26, 0);
        int l = 0;
        for (int i = 0; i < s1.size(); ++i) {
            s1_windows[s1[i] - 'a']++;
        }


        for (int r = 0; r < s2.size(); ++r) {
            windows[s2[r] - 'a'] ++;

            //如果 s2 windows長度大於s1.size()
            if ((r-l+1) > s1.size()) {
                //開始縮左邊
                windows[s2[l] - 'a'] --;
                l++;
            }

            if (s1_windows == windows){
                return true;
            }
        }

        return false;
    }
};
