struct TrieNode {
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
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
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            if(!node->child[idx]) {
                // Trie 不記字母，是靠 child 陣列的索引位置 代表字母。
                // 已經隱含了「往字母 (char) 前進」的意義
                node->child[idx] = new TrieNode(); 
            }

            node = node->child[idx];
        }

        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node  = root;
        for (int i = 0; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            if (node->child[idx] == nullptr) {
                // 不存在就代表該字元不在
                return false;
            }

            node = node->child[idx];
        }

        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node  = root;
        for (int i = 0; i < prefix.size(); ++i) {
            int idx = prefix[i] - 'a';
            if (node->child[idx] == nullptr) {
                // 不存在就代表該字元不在
                return false;
            }

            node = node->child[idx];
        }

        return true;
    }
};
