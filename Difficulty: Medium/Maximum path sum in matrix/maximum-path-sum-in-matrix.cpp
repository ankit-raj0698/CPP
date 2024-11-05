//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[502][502];
    int solve(vector<vector<int>> &grid, int N, int row, int col){
        
        if(col < 0 || col >= N)
            return -1e9;
        
        if(row == N-1){
            return grid[row][col];
        }
        
        
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        
            int down = solve(grid, N, row + 1, col) + grid[row][col];
            int leftDiag = solve(grid, N, row + 1, col - 1) + grid[row][col];
            int rightDiag = solve(grid, N, row + 1, col + 1) + grid[row][col];
        
            return dp[row][col] = max({down, leftDiag, rightDiag});
        
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        for(int j = 0; j < N; j++){
            ans = max(ans, solve(Matrix, N, 0, j));
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends