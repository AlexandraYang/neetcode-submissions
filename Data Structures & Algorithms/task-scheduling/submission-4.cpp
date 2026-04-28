class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();

        vector<int> freq(26, 0);
        
        for (auto & t: tasks) {
            freq[t - 'A']++;
        }
        int maxFreq = *max_element(freq.begin(), freq.end());

        int maxCnt = 0;
        for (auto & c : freq) {
            if ( c == maxFreq) {
                maxCnt ++;
            }
        }

        int ans = max(m, (maxFreq - 1) * (n+1) + maxCnt);
        return ans;

    }
};
