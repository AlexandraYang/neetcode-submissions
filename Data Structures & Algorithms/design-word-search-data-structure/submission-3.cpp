struct TrieNode {
    TrieNode* child[26];
    bool isEnd;
};

class WordDictionary {
private:
    TrieNode * root;

    bool mysearch(string & word, int start, TrieNode* node) {
       //必須優先檢查
        if (node == nullptr) {
            return false; 
        }

         if (start == word.size()) {
            return node->isEnd; // 必須是單字結束!!! 易錯
        }


        char tmp = word[start];
        if (tmp == '.') {
            // '.' 可以匹配任意字母
            for (int i = 0; i < 26; ++i) {
                if (node->child[i] && mysearch(word, start+1, node->child[i])) {
                    return true; // 只要有任一條路成功
                }
            }
            return false; // 沒有任何一條路成功
        } else {
           int idx = tmp - 'a';
           return mysearch(word, start+1, node->child[idx]);
        }
         
    }
public:
    WordDictionary() {
        root = new TrieNode();                
    }
    
    void addWord(string word) {
        TrieNode * node = root;
        for (int i = 0; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            if (!node->child[idx]) {
                node->child[idx] = new TrieNode();
            }
            node = node->child[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        // do some backtracking
        return mysearch(word, 0, root); // str, start_idx
    }
};
