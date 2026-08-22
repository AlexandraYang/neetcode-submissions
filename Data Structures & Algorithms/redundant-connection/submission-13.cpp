class Solution {
private: 
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x) {
            //假設x的parent就是x, 那又是直接把root 吐出來
            return x;
        }

        //假設x's parent 也不是x
        return parent[x] = find(parent[x]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // recall: 
        // 直覺是要用union join 去找出共同root的 
        int n = edges.size();
        parent.resize(n+1);

        //把x 存去parent
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        } 

        for (int n = 0; n < edges.size(); ++n) {
            int x = edges[n][0];
            int y = edges[n][1];

            int rootX = find(x);
            int rootY = find(y);

            if (rootX == rootY) {
                return {x,y};
            }

            //若不同的話 要把他們group跟group之間 產生關聯
            parent[rootX] = rootY;
        }

        return {};

    }
};
