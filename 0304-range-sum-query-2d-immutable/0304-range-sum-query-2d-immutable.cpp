class NumMatrix {
public:

    // Note : make sure to handle prefix sum for col1 = 0 
    // as we are doing grid[i][col1 - 1]

    vector<vector<int>> grid;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Resize the grid to match the matrix dimensions
        grid.resize(n, vector<int>(m));
        for(int i = 0; i < matrix.size(); i++){
            int sum = 0;
            for(int j = 0; j < matrix[i].size(); j++){
                sum  += matrix[i][j];
                grid[i][j] = sum;

            }
        }

        // print prefix sum
        /*
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                 cout << grid[i][j]  << " ";
            }
            cout << endl;
        }
        */
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++){
                int leftSum = col1 == 0 ? 0 : grid[i][col1 - 1];
                sum += grid[i][col2] - leftSum;           
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */