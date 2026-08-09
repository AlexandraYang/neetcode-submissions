class Solution {
private: 
    vector<int> parent; 
    int find(int x) {

        //假設找到最後 root 就是自己 
        if (parent[x] == x) {
            return x;
        }

        /*
            先 find(parent[x])
            ↓
            得到 root
            ↓
            parent[x] = root
            ↓
            這個 assignment 的結果就是 root
            ↓
            return root    
        */
        return parent[x] = find(parent[x]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        // node 是從 1 開始，所以需要 n + 1
        parent.resize(n + 1);

        // node 從1 開始。須小心
        // 一開始每個 node 都是自己的 root
        //
        // 1 -> 1
        // 2 -> 2
        // 3 -> 3
        for (int i = 1; i < n; ++i) {
            parent[i] = i;
        }

        // 一條一條處理每個 edge
        for (int a = 0; a < edges.size(); ++a) {
            int x = edges[a][0];
            int y = edges[a][1];

            int rootX = find(x);
            int rootY = find(y);

            if (rootX == rootY) {
                //假設兩個root 依樣代表有cycle 
                //要小心釋回傳x & y, 而非他們的parent 
                return {x, y};
            }

            //如果不一樣 則代表rootX & rootY 目前屬於不同group 
            // 題目現在給了一條 edge，把兩個原本不連通的 group 接起來，所以我們要更新 parent，記錄這個新的連通關係。
            // parent[rootY] = rootX; 反著寫也可以哦
            parent[rootX] = rootY;
        }

        return {};
    }
};
