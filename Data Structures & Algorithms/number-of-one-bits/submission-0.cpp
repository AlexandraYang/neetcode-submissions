class Solution {
public:
    int hammingWeight(uint32_t n) {
        if (n==0) {
            return 0;
        }
 
        int cnt = 0;
        while(n) {
            n = n &(n-1);
            cnt++;
        }

        return cnt;
    }
};
