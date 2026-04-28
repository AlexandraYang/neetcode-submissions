class Solution {
private:
    bool dfs(vector<vector<int>>&graph, int i, vector<int>& state) {
        if (state[i] == 1) {
            //訪問到正在訪問的 即為有環
            return false;
        }

        if (state[i] == 2) {
            return true; //走完了
        }

        state[i] = 1; //mark正在訪問

        //走過每一個必修對應到的課
        for (auto & d : graph[i]) {
            if (false == dfs(graph, d, state)) {
                return false;
            }
        }

        state[i] = 2; // mark 修完課

        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //建立graph
        vector<vector<int>> graph(numCourses);
        for (auto & pre: prerequisites) {
            int a = pre[0]; //想修
            int b = pre[1]; //需修
            graph[b].push_back(a); // b->a
        }
        // state 需要0 未曾訪問過，1 正在訪問 ；2 完成
        vector<int> state(numCourses, 0);
        
        //每一個pre 都要iter過
        for (int i = 0; i < numCourses; ++i) {
            if (false == dfs(graph, i, state)) {
                return false;
            }
        }

        return true;
    }
};
