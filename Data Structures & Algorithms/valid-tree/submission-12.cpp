class Solution {
private:
    bool is_cycle_in_undirected_graph(int node, int parent, vector<vector<int>>& graph, vector<bool> & visited) {
        // set current node visited
        visited[node] = true;

        for (int neighbor: graph[node]) {
            // look back  
            if (parent == neighbor) {
                continue;
            }


            // Check if visited or not 
            if (visited[neighbor] == true) {
                return true;
            }

            if (is_cycle_in_undirected_graph(neighbor, node, graph, visited)) {
                return true;
            }

            
        }

        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // step1: create graph 
        vector<vector<int>> graph(n);
        for (int i =0; i < edges.size();++i) {
            int a = edges[i][0];
            int b = edges[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);

        }

        // step2:  Check if cycle in graph 
        vector<bool> visited(n, false);
        if (is_cycle_in_undirected_graph(0, -1, graph, visited)) {
            //If cycle, then is not a valid tree 
            return false;
        }

        // step 3: check connected !!! 很重要!!! 
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                return false;
        }

        return true;
    }
};
