class Solution {
private: 
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>> & mp) {
        if (r < 0 || c < 0 || r >= heights.size() ||  c >= heights[0].size()) {
            return;
        }

        if (mp[r][c] == true) {
            //已經拜訪過了 先return 
            return;
        }

        mp[r][c] = true;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < dirs.size(); ++i) {
            int nr = r + dirs[i].first;
            int nc = c + dirs[i].second;


             if (nr < 0 || nc < 0 || nr >= heights.size() || nc >= heights[0].size()) {
                //NOTE!!! 上下左右 任一個方向不行 就是bypass掉就好 
                //萬一是 return 那就全部都不行了 
                
                continue;

            }

            if (heights[r][c] <= heights[nr][nc]) {
                dfs(nr, nc, heights, mp);
            }



        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(); 
        int n = heights[0].size();
       
        //每次都忘記!!
        vector<vector<bool>> pacific_mp(m,vector<bool>(n, false));
        vector<vector<bool>> atlantic_mp(m,vector<bool>(n, false));
        vector<vector<int>> ans;
        
        // Pacific 
        //最上面
        for (int c = 0; c < n; ++c) {
            //row = 0
            dfs(0, c, heights, pacific_mp);
        }

        //最左邊 
        for (int r = 0; r < m; ++r) {
            //col = 0
            dfs(r, 0, heights, pacific_mp);
        }


        // Atlantic 
        // 最右邊 col = n - 1
        for (int r = 0; r < m; ++r) {
            //col = 0
            dfs(r, n - 1, heights, atlantic_mp);
        }

        //最下面 
         for (int c = 0; c < n; ++c) {
            //row = m-1
            dfs(m-1, c, heights, atlantic_mp);
        }

        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (atlantic_mp[i][j] == true && pacific_mp[i][j] == true) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;

    }
};
