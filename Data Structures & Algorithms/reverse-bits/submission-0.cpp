class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0; i < 32; ++i) { //不能while!!! 
            ans <<=1;
            ans = ans | (n & 1); // 只取最後一位!! 易錯!!
            n >>= 1;
            
        }
        return ans;
    }
};
