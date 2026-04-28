class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int l = 0;
        int r = numbers.size()-1;
        while(l < r) {
            if (numbers[l] + numbers[r] > target) {
                r--;
            } else if (numbers[l] + numbers[r] < target){
                l++;
            } else {
                return {l+1, r+1}; //假設是 1-indexed array,
            }
        }

        return {};
    }
};
