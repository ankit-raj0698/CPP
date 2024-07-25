//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    const int mod = 1e9 + 7;
    int solve(int ind, int target, vector<int>& arr,vector<vector<int>> &dp){
        if(ind < 0)
            return target == 0 ? 1 : 0;
            
        if(dp[ind][target] != -1)
            return dp[ind][target];
        
        int nottaken = solve(ind - 1, target, arr,dp) % mod;
        
        int taken = 0;
        if(arr[ind] <= target)
            taken = solve(ind - 1, target - arr[ind], arr,dp) % mod;
        
        return dp[ind][target] = (nottaken + taken) % mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += arr[i];
        
        if ((sum - d) < 0 || (sum - d) % 2 != 0)
            return 0;
            
        int target = (sum - d)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1, target, arr, dp );
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