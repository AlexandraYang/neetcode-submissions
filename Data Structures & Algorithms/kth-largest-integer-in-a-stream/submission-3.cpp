class KthLargest {
private:
    priority_queue<int, vector <int>, greater<int>> minHeap;//from small to big
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
       this->k = k;
       for (int i = 0; i< nums.size(); ++i) {
            minHeap.push(nums[i]);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
       }
    }
    // 3 4 5 
    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
        } else {
            if (minHeap.top() < val) {
                minHeap.push(val);
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};
