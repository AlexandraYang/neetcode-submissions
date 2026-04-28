class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix.size() -1;

        while(l<r) {
            for(int i = 0; i < r-l; ++i) {
                int top = l;
                int bottom = r;

                int topLeft = matrix[top][l+i];
                
                // 左下 複製到 左上 
                //但左下那個腳色 [bottom - i = 左下的 index 會隨著 i 往上走]
                matrix[top][l+i] = matrix[bottom-i][l];

                // 右下 到 左下
                 matrix[bottom-i][l] = matrix[bottom][r-i]; 

                 // 右上到 右下
                 matrix[bottom][r-i] = matrix[top+i][r];

                 // 左上 到 右上
                 matrix[top+i][r] =  topLeft;

            }
            l++;
            r--;
        }
    }
};
