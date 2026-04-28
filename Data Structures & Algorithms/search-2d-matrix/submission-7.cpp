class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size(); // 

        int l = 0;
        int r = m*n-1;
        //mapping 

        while(l <= r) {
            int mid =  l + (r-l)/2;
            int i = mid /n;
            int j = mid % n;
            if(matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                //mid 比目標大 代表 右邊更大 右邊都不要
                r = mid -1;
            } else {
                l = mid +1;
            }
        }

        return false;
        
    }
};
