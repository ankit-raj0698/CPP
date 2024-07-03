//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int solve(vector<int>& height, int index,int k, vector<int>& dp){
        if(index == 0)
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
            
        int ans = INT_MAX;  
        for(int j = 1; j <= k; j++){
            // n-1, n-2 .....n-k
            if(index - j >= 0){
                int res = solve(height,index - j,k , dp) + abs(height[index] - height[index - j]);
                ans = min(ans,res);
            }
        }
        return dp[index] = ans;
    }
  
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n,-1);
        // we are passing the index in 1D DP
        return solve(height,n-1,k,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends