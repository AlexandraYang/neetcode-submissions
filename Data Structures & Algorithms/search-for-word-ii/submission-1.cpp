/*
💡 題目關鍵：
若你每次都用 Word Search I 的 DFS 搜 word，會超時。
所以這題要結合 Trie + DFS 回溯：
先把所有 words 放進 Trie。
從每個格子出發，用 DFS 沿著 Trie 探索。
一旦走到 isEnd == true 的節點，就找到一個字。
*/



class Solution {
private:
    vector<string> *ans;

    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;
        string word;

        TrieNode() {
            for (int i =0; i < 26; ++i) {
                child[i] = nullptr;
            }
            isEnd = false;
            word = "";
        }
    };

    void insert(TrieNode* root, const string& word) {
        
        TrieNode * node = root;
        for (int i =0; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            if (!node->child[idx]) {
                node->child[idx] = new TrieNode();
            }
            node = node->child[idx];
        }
        node->isEnd = true;
        node->word = word;

    }

    void dfs(vector<vector<char>>& board, TrieNode* node, vector<string> & ans, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return;
        }

        char ch = board[i][j];
        if (ch == '#' || !node->child[ch - 'a']) {
            return;
        }

        node = node->child[ch - 'a'];

        if (node->isEnd) {
            ans.push_back(node->word);
            node->isEnd = false;
        }

        board[i][j] = '#';

        dfs(board, node, ans, i+1, j);
        dfs(board, node, ans, i-1, j);
        dfs(board, node, ans, i, j+1);
        dfs(board, node, ans, i, j-1);

        board[i][j] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // step 1: Create words
        TrieNode * root = new TrieNode();
        for (auto & str : words) {
            insert(root, str);
        }

        // step 2: DFS
        vector<string> ans;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, root, ans, i , j);
            }
        }

        return ans;
    }
};
