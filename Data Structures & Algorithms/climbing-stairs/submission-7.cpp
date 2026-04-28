class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two=1;
        if(n<=2) return n;

        for(int i= n-2; i>=0; --i) {
            int tmp=one;
            one=one+two;
            two=tmp;
        }

        return one;
    }
};
