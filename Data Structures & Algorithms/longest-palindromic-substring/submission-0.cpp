class Solution {
private:
    int helper(string s, int left, int right) {
        while (left>=0 && right < s.length() && s[left] == s[right]) {
            left --;
            right ++;
        }

        return right -left -1;
    }
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        int start = 0;
        int maxLen = 0;

        for (int i =0; i < s.length(); ++i) {
            // case 1: odd len string
            int len1 = helper(s, i, i);
            // case 2: even len str
            int len2 = helper(s, i, i+1);

            int len = max(len1, len2);

            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) /2;
            }
        }

        return s.substr(start, maxLen);
    }
};
