class Solution {
public:
    vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int n,m;
    bool isValid(int x, int y){
        if(x >= 0 && x < n && y >= 0 && y < m)
            return true;
        return false;
    }
    bool dfs(vector<vector<char>>& grid, vector<vector<int>> &visited, int i, int j, int parentX, int parentY, char currChar){

        visited[i][j] = 1;
        // traverse the neighbour of curr cell
        for(auto dir: directions){
            int row = i + dir.first;
            int col = j + dir.second;

            if(isValid(row,col) && grid[row][col] == currChar){
                if(!visited[row][col]){
                    if(dfs(grid, visited, row, col, i, j, currChar))
                        return true;
                }
                else if( row != parentX || col != parentY)
                    return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j]){
                    char currChar = grid[i][j];
                    if(dfs(grid, visited, i, j, -1, -1, currChar))
                        return true;
                }              
            }
        }
        return false;
    }
};