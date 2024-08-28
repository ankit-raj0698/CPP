//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int helper(vector<vector<int>>& grid, int i, int j1, int j2, int n, int m, vector<vector<vector<int>>> &dp){
        
        // out of bound 
        if( i >= n || j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e9;
            
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        
        // destination
        if(i == n - 1){
            // both robots are in same cell
            if(j1 == j2)
                return dp[i][j1][j2] =  grid[i][j1];
            else
                return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
        }
        
        // for each move of robot 1 there are three moves of robot 2
        // moves : down , leftDiag, rightDiag for each robot
        // there for total 9 moves
        // both robots are changing their rows at same time so only j changes
        
        int maxi = -1e9;
        for(int d1 = -1; d1 <= +1; d1++){
            for(int d2 = -1; d2 <= +1; d2++){
                if(j1 == j2)
                    maxi = max(maxi,grid[i][j1] + helper(grid, i + 1, j1 + d1, j2 + d2, n, m, dp));
                else
                    maxi = max(maxi, grid[i][j1] + grid[i][j2] + helper(grid, i + 1, j1 + d1, j2 + d2, n, m, dp));
            }
        }
        
        return dp[i][j1][j2] = maxi;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m,vector<int>(m, -1)));
        return helper(grid, 0, 0, m - 1, n, m, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends