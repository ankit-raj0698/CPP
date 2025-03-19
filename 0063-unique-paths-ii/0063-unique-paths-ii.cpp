class Solution {
public:
    int n,m;
    int dp[101][101];
    int solve(vector<vector<int>>& grid, int i, int j){
        if(i == n-1 && j == m-1)
            return 1;
        
        if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1)
            return 0;
        
        if(i >= n || j >= m)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down = solve(grid, i + 1, j);
        int right = solve(grid, i, j + 1);

        return dp[i][j] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
            return 0;

        memset(dp, -1, sizeof(dp));
        return solve(obstacleGrid, 0, 0);
    }
};