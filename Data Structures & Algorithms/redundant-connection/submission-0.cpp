class Solution {
private:
    vector <int> parent;

    void init (int n) {
        parent.resize(n+1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite (int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) {
            return false;
        }

        parent[rootB] = rootA;
        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        init(n);

        for (auto & e: edges) {
            int u = e[0];
            int v = e[1];
            if (!unite(u, v)) {
                //合併失敗 代表有環
                return e;
            }
        }
        
        return {};
    }
};
