class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // 如果牌數不能被 groupSize 整除，直接 false
        if (hand.size() % groupSize != 0) {
            return false;
        }

        // 使用 map 來記錄每張牌的數量
        map<int, int> count;
        for (auto c: hand) {
            count[c] ++;
        }

        // 當 map 不為空
        while(!count.empty()) {
             // 取最小牌作為 sequence 起點
            int start = count.begin()->first;

            // build a group
            for (int i = 0; i < groupSize; ++i) {
                int need = start +i;

                // 如果缺這張牌，回傳 false
                if(count.find(need) == count.end()) {
                    return false;
                }

                // 用掉這張牌
                count[need]--;

                // 如果這張牌已經用完，就從 map 裡刪掉
                if(count[need] == 0) {
                    count.erase(need);
                }
            }
        }

        // 成功將所有牌分組
        return true;
    }
};
