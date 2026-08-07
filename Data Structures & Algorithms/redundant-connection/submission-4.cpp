class Solution {
private:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);

        // Initially, every node is its own component.
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int rootU = find(u);
            int rootV = find(v);

            // u and v are already connected -> cycle
            if (rootU == rootV) {
                return {u, v};
            }

            // Merge two components
            parent[rootU] = rootV;
        }

        return {};
    }
};