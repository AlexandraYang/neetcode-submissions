class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(); // arr 1
        int n = nums2.size(); // arr 2
        int totol_left_len = (m + n +1)/2; // assuming arr 1 + arr2

        // 較短的陣列 nums1 做 binary search
        int left = 0, right = m;
        while (left <= right) {
            int i = (left+right)/2;
            int j = totol_left_len - i;
            int num1MaxLeft = (i == 0) ? INT_MIN : nums1[i-1];
            int num1MaxRight = (i == m) ? INT_MAX : nums1[i];   
            int num2MaxLeft = (j == 0) ? INT_MIN : nums2[j-1];
            int num2MaxRight = (j == n) ? INT_MAX : nums2[j];   

            if (num1MaxLeft <= num2MaxRight && num2MaxLeft <= num1MaxRight) {
                if ((m+n) % 2 == 1) {
                    return max(num1MaxLeft, num2MaxLeft);
                } else {
                    return (max(num1MaxLeft, num2MaxLeft) + min(num1MaxRight, num2MaxRight))/2.0;
                }
            } else if (num1MaxLeft > num2MaxRight) {
                right = i -1;
            } else {
                left = i +1;
            }
        }

        return -1;
       
    }
};
