class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two = 1;
        // 小於 n -1 是因為button up，n的後兩位都起始為1
        // 就不需要再計算了
        for (int i = 0; i < n-1; ++i) {
            // 本來one 在倒數第二位，two 在倒數第一位
            //往前shift 1位以後，全新的位置是one (one+two)；而two變成倒數第二位 
            int tmp = one;
            one = one + two;
            two = tmp;
        
        }

        return one;
    }
};
