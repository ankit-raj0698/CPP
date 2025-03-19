class Solution {
public:
    
    int solve(vector<vector<int>>& matrix, int n, int i, int j, vector<vector<int>> &dp){       
        // out of bound
        if(i >= n || j < 0 || j >= n)
            return 1e9;
        
        // destination
        if(i == n - 1)
            return matrix[i][j];
        
        if(dp[i][j] != -1e9)
            return dp[i][j] ;
        
        int down = matrix[i][j] + solve(matrix, n, i + 1, j, dp);
        int leftDiag = matrix[i][j] + solve(matrix, n, i + 1, j - 1, dp);
        int rightDiag = matrix[i][j] + solve(matrix, n, i + 1, j + 1, dp);
        
        return dp[i][j] = min({down, leftDiag, rightDiag});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1e9));
        
        int res = INT_MAX;
        for(int j = 0; j < n; j++){
            res = min(res, solve(matrix, n, 0, j, dp));
        }
        
        return res;
    }
};