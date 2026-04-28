class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            //endWord 根本不在，直接回傳0
            return 0;
        }

        queue<pair<string, int>> q; //BFS queue: 放(word, steps)
        q.push({beginWord, 1});

        // start BFS
        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            //找到endWord, 且return steps
            if (word == endWord) {
                return steps;
            }

            for (int i = 0; i < word.size(); ++i) {
                string tmp = word;

                for (char c = 'a'; c <= 'z'; ++c) {
                    tmp[i] = c;
                    if (wordSet.find(tmp) != wordSet.end()) {
                        q.push({tmp, steps+1});

                        wordSet.erase(tmp);
                    }
                }

            }
            
        }

        return 0;
    }
};
