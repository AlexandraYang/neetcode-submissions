class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> st; // 當前 [l, r] 視窗內「所有不重複的字元集合」
        int l = 0;
        int max_len = 0;

        for (int r = 0; r < s.size(); ++r) {
            // 用window [l, r] 永遠沒有重複字元
            while(st.count(s[r])) { //判斷會不會重複
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);
            max_len = max(max_len, r -l +1);
        }

        return max_len;
    }
};
