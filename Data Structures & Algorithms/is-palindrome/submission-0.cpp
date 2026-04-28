class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 0) {
            return true;
        }

        int len = s.size();
        int left = 0, right = s.size() -1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            while (left < right && !isalnum(s[right])) {
                right--;
            }

            while (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left ++;
            right--;
        }

        return true;
    }
};
