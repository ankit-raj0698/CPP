//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    
    int solve(vector<int>& height, int ind, int n, vector<int>& dp){
        if(ind == n - 1)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
            
        int right = INT_MAX;    
        int left = solve(height, ind + 1, n, dp) + abs(height[ind] - height[ind + 1]);
        if(ind + 2 < n)
          right = solve(height,ind + 2, n, dp) + abs(height[ind] - height[ind + 2]);
          
        return dp[ind] = min(left,right);
            
    }
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        
        vector<int> dp(n,-1);
        // we are passing the index in 1D DP
        return solve(height,0, n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends