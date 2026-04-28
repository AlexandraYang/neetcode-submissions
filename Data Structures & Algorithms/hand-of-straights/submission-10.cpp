class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if (hand.size() % groupSize != 0) {
            return false;
        }

        map<int, int> record;
        for (auto x: hand) {
            record[x]++;
        }

        while(!record.empty()) {

            int start = record.begin()->first;

            for (int i = 0; i < groupSize; ++i) {
                int need = start + i;

                if (record.find(need) == record.end()) {
                    return false;
                }

                record[need]--;

                if(record[need] == 0) {
                    record.erase(need);
                }
                
            }
        }
        return true;
    }   
};
