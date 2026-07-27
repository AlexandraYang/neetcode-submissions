class Solution {
private:
    bool is_cycle_in_undircted_graph(int node, int parent, vector<vector<int>> &graph, vector<bool> & visited) {

        visited[node] = true;

        for (int neighbor: graph[node]) {

            if (neighbor == parent) {
                // visited && neighbor == parent → 正常回頭
                continue;
            }

            if (visited[neighbor]) {
                //visited && neighbor != parent → 發現 cycle
                return true; // cycle 
            }

            if (is_cycle_in_undircted_graph(neighbor, node, graph, visited)) {
                return true;
            }
        }

        return false;

    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // step 1: Create Graph UDG  無向圖
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a); //這樣才是雙向圖 
        }

        // step 2: check cycle 
        vector<bool> visited(n, false);
        if (is_cycle_in_undircted_graph(0, -1, graph, visited)) {
            return false;
        }

        // step 3: check connected ? 是啥 
        /*
        沒有拜訪。 代表：
        Graph 有兩個 disconnected component。
        所以：不是 Tree。
        */
        for (int i = 0; i <n; ++i) {
            if (!visited[i]) {
                return false;
            }
        }

        return true; // valid graph 

    }
};
