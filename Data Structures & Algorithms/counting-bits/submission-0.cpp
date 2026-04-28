class Solution {
private:
    int cnt_bits(int src) {
        int cnt = 0;
        while(src) {
            if (src & 1) {
                cnt++;
            }
            src >>= 1;
        }

        return cnt;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);

        for (int i = 0; i <= n; ++i) {
            ans[i] = cnt_bits(i); 
        }

        return ans;
    }
};
