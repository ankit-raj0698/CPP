class Solution {
public:
    
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