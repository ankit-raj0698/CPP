class Solution {
public:
    int n, m;
    vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, vector<vector<int>> &visited){

        visited[i][j] = 1;

        bool status = true;
        if(grid1[i][j] == 0)
            status = false;

        for(auto dir: directions){
            int row = i + dir.first;
            int col = j + dir.second;

            if(row >= 0 && row < n && col >= 0 && col < m &&
                grid2[row][col] == 1 && !visited[row][col])
                    status = dfs(grid1, grid2, row, col, visited) && status;
        }
        return status;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid2[i][j]){
                   if(dfs(grid1, grid2, i, j, visited))
                    ans++;
                }
            }
        }
        return ans;
    }
};