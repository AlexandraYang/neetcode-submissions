class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 2 ptr, sort 
        sort(numbers.begin(), numbers.end());
        int l = 0;
        int r = numbers.size() -1;

        vector<int> tmp;
        while (l < r) {
            if (numbers[l] + numbers[r] > target) {
                r--;
            } else if (numbers[l] + numbers[r] < target) {
                l++;
            } else {
                //剛好match的話
                return {l+1, r+1};


            }
            
        }

        return {};
    }
};
