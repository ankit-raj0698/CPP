class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string> &board){
        // check left
        for(int j = 0; j < col; j++){
            if(board[row][j] == 'Q')
                return false;
        }

        // check left upper diagonal
        int newrow = row;
        int newcol = col;

        while(newrow >= 0 && newcol >= 0){
            if(board[newrow][newcol] == 'Q')
                return false;
            newrow--;
            newcol--;
        } 

        // check left lower diagonal
        newrow = row;
        newcol = col;

        while(newrow < n && newcol >= 0){
            if(board[newrow][newcol] == 'Q')
                return false;
            newrow++;
            newcol--;
        } 

        return true;
    }
    void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans){

        if(col >= n){
            ans.push_back(board);
            return;
        }


        for(int row = 0; row < n; row++){
            if(isSafe(row, col, n, board)){
                board[row][col] = 'Q';
                solve(col+1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        
        solve(0, n, board, ans);
        return ans;
    }
};