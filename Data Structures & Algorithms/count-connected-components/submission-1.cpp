class Solution {
private:
    void dfs(int node, vector<vector<int>>& graph, vector<bool> &visited) {
        visited[node] = true;
        for (int nei : graph[node]) {
            if (false == visited[nei]) {
                dfs(nei, graph, visited);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // step 1: 建立無向圖
        vector<vector<int>> graph(n);
        for (auto& e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;

        for (int i =0; i < n; ++i) {
            if (visited[i] == false) {
                dfs(i, graph, visited);
                count++;
            }
        }

        return count;
    }
};
