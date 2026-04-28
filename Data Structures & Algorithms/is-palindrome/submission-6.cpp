class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;
        while(r > l) {
            // 跳過非字母 與 數字 跟空白
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            while (l < r && !isalnum(s[r])) {
                r--;
            }

            if (towupper(s[r]) == towupper(s[l])) {
                r--;
                l++;
            } else {
                return false;
            }
        }

        return true;
    }
};
