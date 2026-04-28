class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstColZero = false;
        bool firstRowZero = false;

        for (int i = 0; i < m; ++i) {
            // check if zero in row
            //直的
            if(matrix[i][0] == 0) {
                firstColZero = true;
            }
            
        }

        for (int j = 0; j < n ; ++j) {
            // check if zero in row
            if(matrix[0][j] == 0) {
                firstRowZero = true;
            }
        }


        //放mark 到最上 + 最左
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        //根據mark 去歸零
        for (int i = 1; i < m; ++i) {
            if(matrix[i][0] == 0) { //假設最上，橫的有0
                for (int j = 1; j < n; ++j) {
                    //我就把對應的col 全部給0
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < n; ++j) {
            if(matrix[0][j] == 0) { //假設最左，直的有0
                for (int i = 1; i < m; ++i) {
                    //我就把對應的row 全部給0
                    matrix[i][j] = 0;
                }
            }
        }


        //最後才處理標記
        if (firstColZero) {
            //假設直條的是0,  這靠左第一條值得都必須是0
            // 要用row 去計算 因為是往下算
            for (int c = 0; c < m; ++c) {
                matrix[c][0] = 0; 
            }
        }

        if (firstRowZero) {
            //假設直條的是0,  這靠左第一條值得都必須是0
            for (int r = 0; r < n; ++r) {
                matrix[0][r] = 0; 
            }
        }
    }
};
