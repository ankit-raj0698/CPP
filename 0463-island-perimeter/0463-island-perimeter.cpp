class Solution {
public:
    int n, m;

    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &visited){
        // out of bound or blocked then we have encounterd water from land
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return 1;
        
        // when the cell is already visited it will not add to perimeter
        if(visited[i][j] == 1)
            return 0;

        visited[i][j] = 1;

        // try all possible directions
        int left  = dfs(grid, i, j - 1, visited);
        int right = dfs(grid, i, j + 1, visited);
        int up    = dfs(grid, i - 1, j, visited);
        int down  = dfs(grid, i + 1, j, visited);

        return left + right + up + down;
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();
        int perimeter = 0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == 1)
                    perimeter += dfs(grid, i, j, visited);
            }
        }
        return perimeter;
    }
};