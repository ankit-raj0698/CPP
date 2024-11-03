class Solution {
public:
    int m, n;
    int dp[201][201];
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp){
        // out of grid
        if(i >= m || j >= n)
            return 1e9;
        
        if(i == m - 1 && j == n-1)
            return grid[i][j];

        if(dp[i][j] != 1e9)
            return dp[i][j];
        
        int down = solve(grid, i + 1, j, dp) + grid[i][j];
        int right = solve(grid, i, j + 1, dp) + grid[i][j];

        return dp[i][j] =  min(down, right);
        

    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1e9));
        return solve(grid, 0, 0, dp);
        
    }
};