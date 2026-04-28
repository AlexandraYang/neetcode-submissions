/*
💡 題目關鍵：
若你每次都用 Word Search I 的 DFS 搜 word，會超時。
所以這題要結合 Trie + DFS 回溯：
先把所有 words 放進 Trie。
從每個格子出發，用 DFS 沿著 Trie 探索。
一旦走到 isEnd == true 的節點，就找到一個字。
*/

struct TrieNode {
    TrieNode* child[26];
    bool isEnd;
    string word = ""; // 存完整單字，方便取結果

    TrieNode() {
        for (int i =0; i < 26; ++i) {
            child[i] = nullptr;
        }
        isEnd = false;
    }
};



class Solution {
private:
    TrieNode * root;
    void insert(string & words) {
        TrieNode * node = root;
        for (int i = 0; i < words.size(); i ++) {
            int idx = words[i] - 'a';
            if (!node->child[idx]) {
                node->child[idx] = new TrieNode();
            }
            node = node->child[idx];
        }
        node->isEnd = true;
        node->word = words; // 紀錄完整單字
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& ans) {
        // out of boundary
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) {
            return;
        }

        // visited
        char ch = board[r][c];
        if (ch == '#' || !node->child[ch - 'a']) {
            return;
        }

        // move forward
        node = node->child[ch - 'a'];

        // find words
        if (node->isEnd) {
            ans.push_back(node->word);
            node->isEnd = false;
        }

        board[r][c] = '#';

        dfs(board, r+1, c, node, ans);
        dfs(board, r-1, c, node, ans);
        dfs(board, r, c-1, node, ans);
        dfs(board, r, c+1, node, ans);

        board[r][c] = ch;

    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;

        root = new TrieNode();

        // step 1: Create Trie Tree with words
        for (int i = 0; i < words.size(); ++i) {
            insert(words[i]);
        }
        

        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, root, ans);
            }
        }
        
        return ans;
    }
};
