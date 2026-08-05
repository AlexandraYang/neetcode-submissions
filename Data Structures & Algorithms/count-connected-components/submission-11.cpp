class Solution {
private: 
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;

        //須小心 我們要loop的是neighbor們  而不是整張graph
        /*
         - graph.size() = 整張圖有幾個 node
         - graph[node].size() = 這個 node 有幾個 neighbor
        */
        for (int i = 0; i < graph[node].size(); ++i) {
            if (!visited[graph[node][i]]) {
                //avoid unlimited loop
                dfs(graph[node][i], graph, visited);
            }
           
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        // step1: build tree 
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0];
            int b = edges[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);            
        }


        // step2: visited each node + if there is non-visited node, we traverse all node of that group.
        vector<bool> visited(n, false);
        for (int node = 0; node < n; ++ node) {
            if (!visited[node]) {
                //一旦發現一個沒拜訪過的，就ans++ 之後把該group的都走遍
                ans++;

                // 把這個 component 的所有 node 走完
                dfs(node, graph, visited);
            }
        }

        return ans;
    }
};
