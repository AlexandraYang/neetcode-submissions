class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set <int> tmp;
        for (auto a: nums) {
            if (tmp.find(a) == tmp.end()) {
                tmp.insert(a);
            } else {
                return true;
            }
        }

        return false;
    }
};
