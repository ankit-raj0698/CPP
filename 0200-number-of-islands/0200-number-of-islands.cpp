class Solution {
public:
    int n, m;
    vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>> &visited){

        visited[i][j] = 1;
        for(auto dir: directions){
            int row = i + dir.first;
            int col = j + dir.second;

            if(row >= 0 && row < n && col >= 0 && col < m &&
                grid[row][col] == '1' && !visited[row][col])
                    dfs(grid, row, col, visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));
        //memset(visited, 0, sizeof(visited));

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    ans++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return ans;
        
    }
};