class Solution {
private: 
    vector<int> parent;
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        // start from n = 1
        parent.resize(n+1);

        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        for (int a = 0; a < n; ++a) {
            int x = edges[a][0];
            int y = edges[a][1];

            int rootX = find(x);
            int rootY = find(y);

            if (rootX == rootY) {
                return {x, y};
            }

            parent[rootX] = rootY;
        }

        return {};

    }
};
