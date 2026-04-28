class Solution {
private:
    void dfs(int i, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[i] = true;
        for (int nei: graph[i]) {
            if (false == visited[nei]) {
                dfs(nei, graph, visited);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //step1: 無向圖
        vector<vector<int>> graph(n);
        for (auto& e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        //step2: DFS走訪
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (false == visited[i]) {
                dfs(i, graph, visited);
                count++;
            }
        }

        return count;
    }
};
