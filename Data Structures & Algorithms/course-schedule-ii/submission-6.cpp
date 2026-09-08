class Solution {
private: 
    vector<int> ans;
    bool is_directed_graph_cycle(vector<vector<int>> &graph, int i, vector<int> &visited) {
        if (visited[i] == 2) {
            // 2 -> finish
            return false;
        }

        if (visited[i] == 1) {
            return true; // re-visited
        }

        visited[i] = 1;
        for (int next = 0; next < graph[i].size(); ++next) {
            //看剩下還有啥課 ???這邏輯忘了 
            if (is_directed_graph_cycle(graph, graph[i][next], visited)) {
                return true;
            }
        }

        visited[i] = 2;
        ans.push_back(i);

        return false;

    }
public:
     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // step 1: Create graph 
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            int pre = prerequisites[i][1];
            int cur = prerequisites[i][0];
            graph[pre].push_back(cur);
        }

        // step 2: dfs 
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; ++ i) {
            if (is_directed_graph_cycle(graph, i, visited)) {
                return {};//has cycle 
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;  
    }
};

