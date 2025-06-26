class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char ch){
        for(int i = 0; i < 9; i++){
            // check current row
            if(board[row][i] == ch)
                return false;
            // check current col
            if(board[i][col] == ch)
                return false;
            
            // check current 3*3 matrix
            if(board[3 * (row/3) + i/3][3 * (col/3) + i % 3] == ch)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == '.'){
                    for(char ch = '1'; ch <= '9'; ch++){
                        if(isSafe(i, j, board, ch)){
                            board[i][j] = ch;
                            if(solve(board) == true)
                                return true;
                            else
                                board[i][j] = '.';

                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);      
    }
};