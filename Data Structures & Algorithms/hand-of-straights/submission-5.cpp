class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        map<int, int> count;
        for (auto c: hand) {
            count[c] ++;
        }

        while(!count.empty()) {
            int start = count.begin()->first;

            // build a group
            for (int i = 0; i < groupSize; ++i) {
                int need = start +i;

                if(count.find(need) == count.end()) {
                    return false;
                }

                count[need]--;

                if(count[need] == 0) {
                    count.erase(need);
                }
            }
        }

        return true;
    }
};
