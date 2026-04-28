class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char t : tasks) {
            freq[ t - 'A']++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());

        int maxCnt = 0;
        for(auto c: freq) {
            if (c == maxFreq) {
                maxCnt++;
            }
        }

        int ans = max((int)tasks.size(), ((maxFreq-1) * (n+1) + maxCnt));
        return ans;
    }
};
