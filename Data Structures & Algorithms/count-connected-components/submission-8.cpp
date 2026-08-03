class Solution {
private:
    void dfs(int node,
             vector<vector<int>>& graph,
             vector<bool>& visited) {

        visited[node] = true;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited);
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {

        // Step 1: Build undirected graph
        vector<vector<int>> graph(n);

        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // Step 2: Count connected components
        vector<bool> visited(n, false);
        int ans = 0;

        for (int node = 0; node < n; ++node) {

            if (!visited[node]) {
                // 發現新的 component
                ans++;

                // 把這個 component 的所有 node 找完
                dfs(node, graph, visited);
            }
        }

        return ans;
    }
};