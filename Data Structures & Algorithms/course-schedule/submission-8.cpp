class Solution {
private: 
    bool dfs_is_loop(int i, vector<vector<int>> &graph, vector<int> & visited) {

        if (visited[i] == 2) {
            return false; // 我以前檢查過，而且沒有 cycle
        }

        if (visited[i] == 1) {
            return true; // 又走回正在探索中的 node
        }

        visited[i] =1; // visiting 


        // 修完 i 之後，還有幾門課可以修。
        for (int next = 0; next < graph[i].size(); ++next) {
            if (dfs_is_loop(graph[i][next], graph, visited)) {
                return true;
            }
        }
        
        // node i 的先修課都修完了 
        visited[i] =2;

        return false; 
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // step 1: 建立graph 要初始化!
        // pre->current 
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            
            //prerequisites[i] = [a, b] => take course b first if you want to take course a.
            int pre = prerequisites[i][1]; // b才是先修課 
            int current = prerequisites[i][0]; 

            // pre->current 
            graph[pre].push_back(current);

        }

        // step2: 開始對 每一堂課dfs 
        // 去找有向圖 是否有loop 
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {

            //假設 有loop return true 
            if (dfs_is_loop(i, graph, visited)) {
                return false;
            }
        }

        return true; //能不能修完所有課？ 可以!
    }
};
