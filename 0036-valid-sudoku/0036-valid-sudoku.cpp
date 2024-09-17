class Solution {
public:

    bool checkBox(int rowStart, int rowEnd, int colStart, int colEnd, vector<vector<char>>& board){
        unordered_set<char> s;
        for(int row = rowStart; row <= rowEnd; row++){
            for(int col = colStart; col <= colEnd; col++){
                if(board[row][col] == '.')
                    continue;
                if(s.find(board[row][col]) != s.end())
                    return false;
                
                s.insert(board[row][col]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        // check row wise
        for(int row = 0; row < 9; row++){
            unordered_set<char> s;
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.')
                    continue;
                if(s.find(board[row][col]) != s.end())
                    return false;
                
                s.insert(board[row][col]);
            }
        }

        // check col wise
        for(int col = 0; col < 9; col++){
            unordered_set<char> s;
            for(int row = 0; row < 9; row++){
                if(board[row][col] == '.')
                    continue;
                if(s.find(board[row][col]) != s.end())
                    return false;
                
                s.insert(board[row][col]);
            }
        }

        // check all the 9 boxes
        for(int row = 0; row < 9; row+=3){
            for(int col = 0; col < 9; col+=3){
                int rowStart = row;
                int rowEnd = row + 2;
                int colStart = col;
                int colEnd = col + 2;

                if(!checkBox(rowStart, rowEnd, colStart, colEnd, board))
                    return false;
            }
        }

        return true;
    }
};