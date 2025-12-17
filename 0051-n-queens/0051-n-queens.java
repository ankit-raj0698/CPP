class Solution {

    boolean check(int row, int col, int n, char[][] board){

        // check queen in left row
        for(int j = 0; j < col; j++){
            if(board[row][j] == 'Q')
                return false;
        }

        int newRow = row;
        int newCol = col;

        // check upper diagonal
        while(newRow >= 0 && newCol >= 0){
            if(board[newRow][newCol] == 'Q')
                return false;
            newRow--;
            newCol--;
        }

        newRow = row;
        newCol = col;

        // check lower diagonal
        while(newRow < n && newCol >= 0){
            if(board[newRow][newCol] == 'Q')
                return false;
            newRow++;
            newCol--;
        }
        return true;
    }

    

    void solve(int col, int n, char[][] board, List<List<String>> ans, boolean[] leftRow, boolean[] lowerDiag, boolean[] upperDiag){

        if(col >= n){
            // store ans
            List<String> temp = new ArrayList<>();
            for(int i = 0; i < n; i++){
                temp.add(new String(board[i]));
            }
            ans.add(temp);
            return;
        }

        // for(int row = 0; row < n; row++){
        //     if(check(row, col, n, board)){
        //         board[row][col] = 'Q';
        //         solve(col+1, n, board, ans);
        //         board[row][col] = '.';
        //     }
        // }

        for(int row = 0; row < n; row++){
                if((leftRow[row] == false) && (lowerDiag[row + col] == false) && (upperDiag[n - 1 + col - row] == false)){
                board[row][col] = 'Q';
                leftRow[row] = true;
                lowerDiag[row + col] = true;
                upperDiag[n - 1 + col - row] = true;
                solve(col+1, n, board, ans, leftRow, lowerDiag, upperDiag);
                board[row][col] = '.';
                leftRow[row] = false;
                lowerDiag[row + col] = false;
                upperDiag[n - 1 + col - row] = false;
            }
        }
    }

    public List<List<String>> solveNQueens(int n) {
        char[][] board = new char[n][n];
        List<List<String>> ans = new ArrayList<>();

        boolean[] leftRow = new boolean[n];
        boolean[] lowerDiag = new boolean[2*n - 1];
        boolean[] upperDiag = new boolean[2*n - 1];

        Arrays.fill(leftRow, false);
        Arrays.fill(lowerDiag, false);
        Arrays.fill(upperDiag, false);

        for(int i = 0; i < n; i++)
            Arrays.fill(board[i], '.');
        
        solve(0, n, board, ans, leftRow, lowerDiag, upperDiag);
        return ans;
    }
}