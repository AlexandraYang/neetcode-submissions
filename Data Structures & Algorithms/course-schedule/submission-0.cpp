class Solution {
private:
    bool dfs(int node, vector<vector<int>> & graph, vector<int>& state) {
        if (state[node] == 1) {
            //發現環
            return false;
        }

        if (state[node] == 2) {
            // 已經訪問過
            return true;
        }

        state[node] = 1;

        for (int nei:graph[node]) {
            if (!dfs(nei, graph, state)) {
                return false;
            }
        }

        state[node] = 2; // 標記成visited

        return true;

    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //建立adjant list
        vector<vector<int>> graph(numCourses);
        for (auto & pre: prerequisites) {
            int a = pre[0]; // 要修的課
            int b = pre[1]; // 先修的課
            graph[b].push_back(a); // b->a, b先修 a後修
        }

        vector<int> state(numCourses, 0); // 0 -> 未訪問；1->訪問中；2 -> 已完成
        for (int i =0; i < numCourses; ++i) {
            if (state[i] == 0) {            //假設這堂課還沒被DFS過
                if (!dfs(i, graph, state)) { //從這node開始DFS
                    return false;           //假設DFS發現有環，不可能修完
                }
            }
        }

        return true; //沒有環  即可修完
    }
};
