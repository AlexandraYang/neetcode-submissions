class Solution {
private:
    bool dfs(int node, int prev_node, unordered_set<int>& visit, vector<vector<int>>& adj) {
        if (visit.count(node)) {
            return false;
        }

        visit.insert(node);
        for (int nei: adj[node]) {
            if (nei == prev_node) {
                //假設是上一個node 先忽略 往下找
                continue;
            }

            if (false == dfs(nei, node, visit, adj)) {
                return false;
            }
        }

        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n-1) {
            //有多的edge 代表一定有環
            return false;
        }

        vector<vector<int>> adj(n);
        for (const auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set <int> visit;
        if (false == dfs(0, -1, visit, adj)) {
            return false;
        } 

        return visit.size() == n;
    }
};
