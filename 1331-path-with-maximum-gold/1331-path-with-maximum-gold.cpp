class Solution {
public:

    int n, m;
    vector<pair<int,int>> direction = {{0,1},{0,-1},{-1,0},{1,0}};
    int dfs(vector<vector<int>>& grid, vector<vector<int>> &visited, int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] == 0)
            return 0;

        int gold = grid[i][j];
        int maxgold = 0;
        visited[i][j] = 1;

        for(auto dir: direction){
            int row = i + dir.first;
            int col = j + dir.second;

            maxgold = max(maxgold, dfs(grid, visited, row, col));
        }
        visited[i][j] = 0;
        return maxgold + gold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        int maxgold = 0;
        vector<vector<int>> visited(n, vector<int>(m,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    maxgold = max(maxgold, dfs(grid, visited, i, j));
                }
            }
        }
        
        return maxgold;
        
    }
};