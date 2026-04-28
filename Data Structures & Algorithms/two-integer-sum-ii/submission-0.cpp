class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //遞增vector src
        vector <int> ans;
        int left = 0;
        int right = numbers.size() -1;

        while (left < right) {
           int tmp = numbers[left] + numbers[right];

            if (tmp  == target) {
                return {left +1, right +1};
            } else if (tmp < target) {
                left++;
            } else {
                right --;
            }
        }

        return {};
        
    }
};
