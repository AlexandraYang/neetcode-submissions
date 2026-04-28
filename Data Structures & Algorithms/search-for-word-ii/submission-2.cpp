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

    void dfs(vector<vector<char>>& board, TrieNode* node, vector<string>& ans, int i, int j) {
        // ① 檢查邊界：超出棋盤範圍就直接返回
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return;
        }

        // ② 取出目前格子的字母
        char ch = board[i][j];

        // ③ 若該格已被訪問（'#'），或 Trie 沒有對應此字母的子節點 → 剪枝返回
        if (ch == '#' || !node->child[ch - 'a']) {
            return;
        }

        // ④ Trie 走下一層：移動到對應當前字母的節點
        node = node->child[ch - 'a'];

        // ⑤ 若該節點是某個字的結尾，表示找到完整單字
        if (node->isEnd) {
            ans.push_back(node->word);   // 把這個字加入答案
            node->isEnd = false;         // 標記為已使用，避免重複加入
        }

        // ⑥ 標記當前格子為已訪問，避免在同一路徑中重複使用
        board[i][j] = '#';

        // ⑦ 向四個方向繼續深度搜尋（下、上、右、左）
        dfs(board, node, ans, i + 1, j); // 往下
        dfs(board, node, ans, i - 1, j); // 往上
        dfs(board, node, ans, i, j + 1); // 往右
        dfs(board, node, ans, i, j - 1); // 往左

        // ⑧ 回溯：將格子還原成原本字母，讓其他搜尋路徑可以使用
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
