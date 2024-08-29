//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9 + 7;
    int solve(vector<int>& arr, int n, int ind, int sum, vector<vector<int>>&dp){
        if(ind == n){
            if(sum == 0)
                return 1;
            return 0;
        }
        
        if(ind > n || sum < 0)
            return 0;
            
        if(dp[ind][sum] != -1)
            return dp[ind][sum];
        
        int notTake = solve(arr, n, ind + 1, sum, dp) % mod;
        int take =  solve(arr, n, ind + 1, sum - arr[ind], dp) % mod;
        
        return dp[ind][sum] = (take + notTake) % mod;
    }
  
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        if(sum - d < 0 || (sum - d) % 2 != 0)
            return 0;
        
        int target = (sum - d) / 2;
        
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        
        return solve(arr, n, 0, target, dp);

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends