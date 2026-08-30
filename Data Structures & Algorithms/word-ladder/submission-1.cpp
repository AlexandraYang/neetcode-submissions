class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        // wordSet 存放所有合法的 word
        // 用來快速確認我們產生的新 word 是否存在於 wordList
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // 如果 endWord 根本不在 wordList 裡
        // 就不可能走到 endWord
        if (!wordSet.count(endWord)) {
            return 0;
        }

        // Word Ladder 本質上是一個「最短路徑」問題
        // 每個 word 都是一個 Node
        // 如果兩個 word 只差一個 char，就代表兩個 Node 之間有 edge
        //
        // 這是一個 implicit graph
        // 我們不需要事先建立完整的 graph
        // 而是在 BFS 探索每個 word 時，再動態找它的 neighbors
        queue<string> q;
        q.push(beginWord);

        // BFS 的 level 代表 transformation sequence 中有幾個 word
        int level = 1;

        while (!q.empty()) {

            // 目前 queue 裡的 word 都屬於同一個 BFS level
            // 先記住目前這一層有多少個 Node
            int size = q.size();

            for (int i = 0; i < size; ++i) {

                // 取出一個待探索的 Node
                string word = q.front();
                q.pop();

                // 第一次找到 endWord 時
                // 因為 BFS 是一層一層搜尋，所以一定是最短路徑
                if (word == endWord) {
                    return level;
                }

                // 開始尋找目前 word 的所有 neighbors
                //
                // 每一個 index 都嘗試替換成 a ~ z
                // 這樣就能產生所有「只差一個 char」的可能 word
                for (int i = 0; i < word.size(); ++i) {

                    // 暫存原本的 char
                    // 因為等等會暫時修改這個位置
                    char original = word[i];

                    for (char c = 'a'; c <= 'z'; ++c) {

                        // 暫時把目前 index 的 char 替換掉
                        word[i] = c;

                        // 檢查這個產生的新 word 是否存在於 wordSet
                        if (wordSet.count(word)) {

                            // 找到合法的 neighbor
                            //
                            // 先放進 queue
                            // 因為這個 word 是我們「接下來要探索的 Node」
                            q.push(word);

                            // 從 wordSet 移除
                            // 避免之後重複拜訪同一個 word
                            wordSet.erase(word);
                        }
                    }

                    // 這個 index 嘗試完 a ~ z 後
                    // 把 char 恢復成原本的樣子
                    word[i] = original;
                }
            }

            // 目前這一層全部探索完
            // 下一輪就是下一個 BFS level
            ++level;
        }

        // BFS 結束仍然沒有找到 endWord
        return 0;
    }
};