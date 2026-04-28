struct TrieNode {
    TrieNode *child[26];
    bool isEnd;

    TrieNode () {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }

        isEnd = false;
    }
};

class PrefixTree {
private:
    TrieNode * root;

public:
    PrefixTree() {
        root = new TrieNode(); // 會不小心忘記create new node    
    }
    
    void insert(string word) {
        TrieNode* node = root;
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
        TrieNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            if (!node->child[idx]) {
                return false;
            }
            node = node->child[idx];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); ++i) {
            int idx = prefix[i] - 'a';
            if (!node->child[idx]) {
                return false;
            }
            node = node->child[idx];
        }
        return true;
    }
};
