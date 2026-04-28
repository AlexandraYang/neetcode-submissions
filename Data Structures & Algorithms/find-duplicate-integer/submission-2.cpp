class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        // loop until slow and fast intersec to each other
        do {
            slow = nums[slow]; // slow 走一步  想像nums array 的val 就是ptr
            fast = nums[nums[fast]];  // fast 走兩步
        } while (slow != fast);

        // make slow get back to head
        // slow 1 step ; fast 1 step
        // entry point will be found when fast and slow intersect to each other
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
