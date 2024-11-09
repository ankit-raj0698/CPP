class Solution {
public:
    
    //initial call : solve(0,0)
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp){
               
        // out of bound case
        if(i >= m || j >= n)
            return 0;
        
        // reached the destination
        if(i == m-1 && j == n-1)
            return 1;
        
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // robot can either go down or right
        int down = solve(i + 1, j, m, n, dp);
        int right = solve(i, j + 1, m, n, dp);
        
        return dp[i][j] = down + right;
        
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
};