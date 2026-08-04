class Solution {
private: 
    bool is_cycle_in_graph(int node, vector<int>& visited, vector<vector<int>>& graph) {
        visited[node] = 2; //visiting 

        for (auto next: graph[node]) {
        	if (visited[next] == 2) {
        		//假設也在拜訪中 那就是loop 
        		return true; 
        	}

        	if (visited[next] == 1) {
        		//已經拜訪過 
        		continue;
        	}

        	if (is_cycle_in_graph(next, visited, graph)) {
        		return true;
        	}

        	
        }

        visited[node]  = 1; //真的拜訪完畢 但是是node拜訪完他的鄰居!!! 
        return false;

        
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //find cycle in undirection graph 

        // 1. build graph 
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            //先上 b 在上a 
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            graph[b].push_back(a);
        }

        vector<int> visited(numCourses, 0);// 2=> visiting, 1-> visited 
        for (int j = 0; j < numCourses ; ++j) {
            if (is_cycle_in_graph(j, visited, graph)) {
                return false;
            }
        }
        return true;
    }
};
