class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (!wordSet.count(endWord)) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);

        int level = 1;
        while(!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; ++i) {
                string word = q.front();
                q.pop();

                if (word == endWord) {
                    return level;
                }

                for (int i = 0; i < word.size(); ++i) {
                    char original = word[i];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;

                        if (wordSet.count(word)) {
                            q.push(word);
                            wordSet.erase(word);
                        }
                    }

                    word[i] = original;
                }

            }

            level ++;
        }

        return 0;
    }
};
