class Solution {
private:
    vector<int> order;
    bool dfs(vector<vector<int>> &graph, int i, vector<int> & state) {
        // 0 unvisited; 1 visiting; 2 complete
        if (state[i] == 1) {
            return false; //有環
        }

        if (state[i] == 2) {
            return true; 
        }

        state[i] = 1; //走過的給1 visiting

        for (auto & d : graph[i]) {
            if (!dfs(graph, d, state)) {
                return false;
            }
        }


        state[i] = 2;
        order.push_back(i);

        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto &pre: prerequisites) {
            int a = pre[0];
            int b = pre[1];
            graph[b].push_back(a); // b 基礎電磁波 ，a 高階電磁波
        }

        vector<int> state(numCourses, 0); //state 且都未visited
        for (int i = 0; i < numCourses; ++i) {
            
            if (false == dfs(graph, i, state)) {
                return {};
            }
            
        }
        
        reverse(order.begin(), order.end());
        return order;
    }
};
