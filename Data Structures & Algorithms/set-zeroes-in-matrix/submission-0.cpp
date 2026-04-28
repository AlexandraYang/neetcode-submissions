class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> record;

        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    record.push_back({i, j});
                }
            }
        }

        for (auto & p: record) {
            int r = p.first;
            int c = p.second;


            for (int col = 0; col < n; ++col) {
                matrix[r][col] = 0;
            }

            for(int row = 0; row < m; ++row) {
                matrix[row][c] = 0;
            }
        }

        
    }
};
