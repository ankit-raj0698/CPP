class Solution {
public:
    int n,m;
    int dp[301][301];
    int solve(vector<vector<int>>& matrix, int i, int j){
        if(i >= n || j >= m)
            return 0;

        if(matrix[i][j] ==  0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // make three calls to find no. of matrices
        int right = solve(matrix, i, j+1);
        int down = solve(matrix, i + 1, j);
        int diag = solve(matrix, i + 1, j + 1);

        return dp[i][j] =  1 + min({right, down, diag});
    }
    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        memset(dp, -1, sizeof(dp));

        int result = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 1)
                    result += solve(matrix, i, j);
            }
        }
        return result;
    }
};