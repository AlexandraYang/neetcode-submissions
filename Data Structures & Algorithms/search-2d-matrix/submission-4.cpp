class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //確切找某個數 是否存在在matrix 內
        int n = matrix[0].size();
        int m = matrix.size();

        int l = 0;
        int r = m *n -1 ; // r就是整個arr size

        while (l <= r)  {
            int mid = l + (r-l)/2;

            int i = mid/n;
            int j = mid %n;

            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                r = mid - 1;
                
            } else {
                l = mid + 1;
            }
        }

        return false;
        
    }
};
