class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool has0 = false, has1 = false, has2 = false;

        for (auto &t: triplets) {
            if (t[0] > target[0] ||
                t[1] > target[1] ||
                t[2] > target[2]
            ) {
                continue;
            }

            if (t[0] == target[0]) {
                has0 = true;
            }

            if (t[1] == target[1]) {
                has1 = true;
            }

            if (t[2] == target[2]) {
                has2 = true;
            }
        }

        return has0 && has1 && has2;
    }
};
