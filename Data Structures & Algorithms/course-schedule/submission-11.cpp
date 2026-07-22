class Solution {
private: 
    bool dfs_is_loop_in_directed_graph(int i, vector<vector<int>> &graph, vector<int>& visited) {
        if (visited[i] == 2) {
            return false;
        }

        if (visited[i] == 1) {
            return true;
        }

        visited[i] = 1;

        for (int next_class : graph[i]) {
            if (dfs_is_loop_in_directed_graph(next_class, graph, visited)) {
                return true;
            }
        }

        //node i 的所有後續課程都檢查完成，沒有 cycle
        visited[i] = 2;


        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // step 1: create graph 
        vector<vector<int>> graph (numCourses);
        
        for (int i = 0; i < prerequisites.size(); ++i) {
            int pre = prerequisites[i][1];
            int current = prerequisites[i][0];

            //修完pre 以後 還有什麼課可以修 
            graph[pre].push_back(current);
        }

        // step 2: loop each course 
        vector<int> visited(numCourses, 0); //define 0 = unvisited, 1=visiting, 2 = visited 
        for (int node = 0; node < numCourses; ++node) {
            if (dfs_is_loop_in_directed_graph(node, graph, visited)) {
                return false; // 因為有cycle 所已完成不了 
            }
        }


        return true; //no loop, yes ! can finish 

    }
};
