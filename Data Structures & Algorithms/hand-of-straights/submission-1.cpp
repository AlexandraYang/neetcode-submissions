class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        sort(hand.begin(), hand.end());

        unordered_map<int, int> count;
        for (auto c: hand) {
            count[c] ++;
        }

        for (int card: hand) {

            if(count[card] == 0) {
                continue;
            }

            // build a group
            for (int i = 0; i < groupSize; ++i) {
                int need = card +i;

                if(count[need] == 0) {
                    return false;
                }

                count[need]--;
            }
        }

        return true;
    }
};
