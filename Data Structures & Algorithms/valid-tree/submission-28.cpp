class Solution {
private: 
    bool is_cycle_in_graph(int node, int parent, vector<bool> &visited, vector<vector<int>>& graph) {
        visited[node] = true;


        for (auto neightbor : graph[node]) {
            if (neightbor == parent) {
                //只是回頭 not cycle
                continue;
            }

            if (visited[neightbor]) {
                // 已拜訪過，而且不是 parent
                // => cycle
                return true;
            }

            if (is_cycle_in_graph(neightbor, node, visited, graph)){
                return true;
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //check unordered_graph 
        // build graph 
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0];
            int b = edges[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // dfs from node 0, parent -1
        vector<bool> visited(n, false);
        if (is_cycle_in_graph(0, -1, visited, graph)) {
            //since there's cycle, its not a valid tree 
            return false;
        }


        // check if unconnected graph 
        for (int n =0; n < visited.size(); ++n) {
            if (!visited[n]) {
                return false;
            }
        }

        return true;
    }
};
