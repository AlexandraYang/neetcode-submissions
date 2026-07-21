class Solution {
private: 
    bool dfs(int node, vector<vector<int>> & graph, vector<int> & visited) {
        // cycle 
        if (visited[node] == 1) {
            return false;
        }


        // already check 
        if (visited[node] == 2) {
            return true;
        }

        // visiting 
        visited[node] = 1;

        for (int next : graph[node]) {
            if (!dfs(next, graph, visited)) {
                return false;
            }
        }

        // finish
        visited[node] = 2;

        return true; 
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for (int i = 0; i< prerequisites.size(); ++i) {
            // {0, 1}  => 要先修1之前 要先上0 
            //  prerequisites[i] = [a, b] indicates 
            // that you must take course b first if you want to take course a.
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];

            // pre -> course 
            // 箭頭永遠代表「修完前面的課，才能修後面的課」。
            //
            // 從 0 可以到 1 
            // graph[0] = {1,2}
            // graph[1] = {3}
            // graph[2] = {}
            // graph[3] = {}
            // 
            // 
            graph[pre].push_back(course);
        }

        vector<int> visited(numCourses, 0);

        for (int i =0; i < numCourses; ++i) {
            if (!dfs(i, graph, visited)) {
                return false;
            }
        }

        return true;
    }
};
