class Solution {
private: 
    //bool: 我們需要知道dfs 有沒有找到cycle 
    bool dfs(int node, int parent, vector<int>& visited ,vector<vector<int>> &graph ) {
        //
        visited[node] = true;
        
        for (int neighbor : graph[node]) {
            if (neighbor == parent) {
                continue;//一般回頭
            }

            if (visited[neighbor] == true) {
                return true; 
            }


            if (dfs(neighbor, node, visited, graph)) {
                return true;
            }
        }

        // 我知道說要檢查parent 是否 有被拜訪之類的 是回頭 
        // 假設是 真的parent 沒有拜訪過 且該node 是拜訪過  那就是cycle 
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // step 1: create bi-direction graph 
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0];
            int b = edges[i][1];

            // make it bi-direction 
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // step 2: call dfs with node & parent & visited vect & graph 
        vector<int> visited(n, false);

        if (dfs(0, -1, visited, graph)) { // start from node 1
            return false;
        }

        // Step 3: Check nodes, and see if there's disconnected components 
        for (int i = 0; i < n; ++i) {
            if (visited[i] == false) {
                return false; // Not a valid tree as long as there's disconnected component 
            }
        }

        return true;
    }
};
