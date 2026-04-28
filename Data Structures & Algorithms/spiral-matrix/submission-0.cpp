class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m =  matrix.size(); // row 幾條
        int n = matrix[0].size(); // col 幾條

        int top = 0;
        int btm = m-1;
        int left = 0;
        int right = n-1;

        vector<int> ans;
        while(top <= btm && left <= right) {
            //往右走
            for(int col = left; col <= right; col++) {
                ans.push_back(matrix[top][col]);
            }
            top++;

            //往下走
            for(int row = top; row <= btm; row++) {
                ans.push_back(matrix[row][right]);
            }
            right --;

            //往左
            if (top <= btm) {
                for (int col = right; col >= left; col --) {
                    ans.push_back(matrix[btm][col]);
                }
                 btm --;
            }
           
            
            //往上
            if (left <= right) {
                for (int row = btm; row>= top; row--) {
                    ans.push_back(matrix[row][left]);
                }
                left++;

            }
            

        }

        return ans;


    }
};
