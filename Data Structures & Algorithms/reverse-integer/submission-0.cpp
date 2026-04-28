class Solution {
public:
    int reverse(int x) {
        int rev = 0; // 所有要reverse的累計
        while (x!=0) {
            int pop = x % 10; // 拿出x的最後一位，就像stack pop一樣
            x = x /10;
           

            if ((rev > INT_MAX/10) || (rev == INT_MAX/10 && pop > 7)) {
                return 0;
            }

            if ( (rev < INT_MIN/10) || (rev == INT_MIN/10 && pop < -8)) {
                return 0;
            }

            rev = rev *10 + pop;
        }

        return rev;
    }
};
