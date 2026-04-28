class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix.size() -1;

        while(l<r) {
            for(int i = 0; i < r-l; ++i) {
                int top = l; // offset 不能當邊界
                int btm = r;

                // 左上暫存
                int topLeft = matrix[top][l + i];

                // 左下 給 左上
                matrix[top][l + i] = matrix[btm - i][l];

                // 右下 給 左下
                matrix[btm - i][l] = matrix[btm][r - i];

                // 右上 給 右下 
                matrix[btm][r - i] = matrix[top + i][r];

                //左上 暫存給 右上
                matrix[top + i][r] = topLeft;
            }

            // layer change
            l++;
            r--;
        }
    }
};
