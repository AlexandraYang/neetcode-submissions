struct TrieNode {
    TrieNode * child[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
        isEnd = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(TrieNode * node, string word, int start) {
        if (!node) {
            //走到沒有的 
            return false;
        }
        if (start == word.size()) {
            return node->isEnd;
        }

        char tmp = word[start];
        if (tmp == '.') {
            for (int i = 0; i < 26; ++i) {
                if (dfs(node->child[i], word, start + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            int childIdx = tmp - 'a';
            return dfs(node->child[childIdx], word, start + 1);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode;
    }
    
    void addWord(string word) {
        TrieNode * node = root;
        for (int i = 0; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            if (!node->child[idx]) {
                //假設node 不存在 新創一個
                node->child[idx] = new TrieNode;
            }
            node = node->child[idx]; // 往下一層
        }
        node->isEnd = true; // 走到最後要set true
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};
