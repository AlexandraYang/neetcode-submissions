class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        // 如果牌的總數不能被 groupSize 整除
        // 代表一定會有剩牌，無法剛好分組
        if (hand.size() % groupSize != 0) {
            return false;
        }

        // 先排序，確保我們是從最小的牌開始處理
        // Greedy 的關鍵：最小牌一定要當作 sequence 的起點
        sort(hand.begin(), hand.end());

        // count 用來記錄每張牌剩下幾張
        // key = 牌的數字
        // value = 這張牌的數量
        unordered_map<int,int> count;

        // 建立 frequency table
        // 例如 hand = [1,2,2,3,3,4]
        // count 會變成：
        // 1->1, 2->2, 3->2, 4->1
        for (int card : hand) {
            count[card]++;
        }

        // 逐張牌檢查
        // 嘗試從這張牌開始建立一個連續 sequence
        for (int card : hand) {
            
            // 如果這張牌已經被之前的 sequence 用掉
            // 就直接跳過
            if (count[card] == 0)
                continue;

            // 嘗試建立一個 group
            // group 需要 groupSize 張連續的牌
            for (int i = 0; i < groupSize; i++) {

                // 需要的牌是 card, card+1, card+2 ...
                int need = card + i;

                // 如果缺少這張牌
                // 就無法形成連續 sequence
                if (count[need] == 0)
                    return false;

                // 使用這張牌
                // 把剩餘數量減 1
                count[need]--;
            }
        }

        // 如果所有牌都成功組成 sequence
        return true;
    }
};