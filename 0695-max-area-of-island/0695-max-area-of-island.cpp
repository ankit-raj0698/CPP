class Solution {
public:
    int n, m;
    vector<pair<int, int>> direction = {{0,1}, {0,-1}, {-1,0}, {1,0}};

    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &visited){
        //out of bound, already visited , blocked
        if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] == 0)
            return 0;
        
        visited[i][j] = 1;
        int area = 1;

        for(auto dir: direction){
            int row = i + dir.first;
            int col = j + dir.second;
            area += dfs(grid, row, col, visited);
        }
        
        return area;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int res = dfs(grid, i, j, visited);
                    ans = max(ans, res);
                }
            }
        }
        return ans;
        
    }
};