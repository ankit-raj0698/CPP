class Solution {
public:
    
    /*
    check row wise if any number is repeated from 1-9 using set
    check col wise if any number is repeated from 1-9 using set
    check in a 3*3 box if any number is repeated from 1-9
    for checking in a box create a method that will take rowStart, rowEnd, colStart, colEnd, board
    and check if any number is repeated from 1-9 using set
    rowStart and colStart value is incremented by 3 and rowEnd = rowStart +2, colEnd = colStart + 2
    */
    
    //check if box(3*3) is valid sudoku
    //Note: mistake done -> row <= rowEnd but i had done row < rowEnd
    bool traverseBox(int rowStart,int rowEnd,int colStart, int colEnd,vector<vector<char>>& board){
        
        unordered_set<char> st;
        for(int row = rowStart; row <= rowEnd; row++){
            for(int col = colStart; col <= colEnd; col++){
                if(board[row][col] == '.')
                    continue;
                if(st.find(board[row][col]) != st.end()){
                    return false;
                }
                st.insert(board[row][col]);
            }
        }
        return true;      
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //check row wise for any repeated no
        for(int row = 0; row < 9; row++){
            unordered_set<char> st;
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.')
                    continue;
                if(st.find(board[row][col]) != st.end()){
                    return false;
                }
                st.insert(board[row][col]);
            }
        }
        
        //check column wise  for any repeated no
        for(int col = 0; col < 9; col++){
            unordered_set<char> st;
            for(int row = 0; row < 9; row++){
                if(board[row][col] == '.')
                    continue;
                if(st.find(board[row][col]) != st.end()){
                    return false;
                }
                st.insert(board[row][col]);
            }
        }
        
        //check box wise  for any repeated no
        for(int row = 0; row < 9; row+=3){
            for(int col = 0; col < 9; col+=3){
                int rowStart = row;
                int rowEnd = row + 2;
                int colStart = col;
                int colEnd = col + 2;
                
                //check if box is valid sudoku
                if(!traverseBox(rowStart,rowEnd,colStart,colEnd,board))
                    return false;
                
            }
        }
        return true;
    }
};