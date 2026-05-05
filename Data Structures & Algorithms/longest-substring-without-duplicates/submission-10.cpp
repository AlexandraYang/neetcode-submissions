class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = s.size()-1;

        int max_len = 0;
        unordered_set<char> st;
        for (int r = 0; r < s.size(); ++r) {
            while(st.count(s[r])) {
                //假設windows出現過
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);
            max_len = max(max_len, r - l +1);
        }

        return max_len;
    }
};
