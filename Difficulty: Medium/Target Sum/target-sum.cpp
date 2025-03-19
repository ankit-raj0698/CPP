//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int dp[101][2001];
    int mod = 1e9 + 7;
    int targetSum(vector<int> &nums, int ind, int target){
        if(ind < 0)
            return target == 0;
        
        if(dp[ind][target] != -1)
            return dp[ind][target];
        
        int not_pick = targetSum(nums, ind - 1, target);
        int pick = 0;
        if(nums[ind] <= target)
            pick = targetSum(nums, ind - 1, target - nums[ind]);
            
        return dp[ind][target] = (pick + not_pick) % mod;
    }
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        // Your code here
        if(n == 1)
            return A[n-1] == target;
        
        int sum = accumulate(begin(A), end(A), 0);
        memset(dp, -1, sizeof(dp));
        if(sum - target < 0 || (sum - target) % 2 != 0)
            return 0;
        target = (sum - target)/2;
        return targetSum(A, n-1, target);
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
        int target;
        cin >> target;

        Solution ob;
        cout << ob.findTargetSumWays(N, arr, target);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends