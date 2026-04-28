class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // bucket sort
        unordered_map <int, int> count;
        for (int n: nums) {
            count[n]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto& entry: count) {
            int val = entry.first;
            int freq = entry.second;

            bucket[freq].push_back(val);
        }

        vector<int> res;
        for (int i = bucket.size() - 1; i > 0; --i) {
            for (int n : bucket[i]) {
                res.push_back(n);

                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res;
    }
};
