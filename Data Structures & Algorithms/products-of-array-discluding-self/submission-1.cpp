class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);
       vector<int> ans;

        //重點是向前遍歷 需要知道我以前的 所以i-1
        for (int i = 1; i < nums.size(); ++i) {
            left [i] = left[i -1] * nums[i-1];
        }

        //重點是向左遍歷 需要知道我以前的 所以j+1
        for (int j = nums.size() -2; j >= 0; --j) {
            right [j] = right[j + 1] * nums[ j +1];
        }

        for (int i = 0; i < nums.size(); ++i) {
           ans.push_back(left[i] * right[i]);
        }

        return ans;
    }
};
