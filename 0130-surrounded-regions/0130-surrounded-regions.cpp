class Solution {
public:
    int n,m;
    vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void dfs(vector<vector<char>>& board, vector<vector<int>> &visited, int i, int j){
        visited[i][j] = 1;

        for(auto dir: directions){
            int row = i + dir.first;
            int col = j + dir.second;

            if(row >= 0 && row < n && col >= 0 && col < m 
                && !visited[row][col] && board[row][col] == 'O')
                dfs(board, visited, row, col);
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i == 0 || i == n-1 || j == 0 || j == m-1) &&
                     !visited[i][j] && board[i][j] == 'O')
                dfs(board, visited, i, j);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};