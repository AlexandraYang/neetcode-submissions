class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
        A _ _ A _ _ A

        
        */
        vector<int> freq(26, 0);
        for (auto &c: tasks) {
            // count maxFreq
            freq[c-'A']++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());

        //check how many char reach to maxFreq
        int maxCnt = 0;
        for(auto & f: freq) {
            if (f == maxFreq) {
                maxCnt++;
            }
        }

        int tmp = ((maxFreq - 1) * (n+1) + maxCnt);
        //
        int ans = max((int)tasks.size(), tmp);
        return ans;
    }
};
