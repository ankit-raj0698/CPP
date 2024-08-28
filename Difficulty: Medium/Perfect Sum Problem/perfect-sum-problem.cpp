//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
// check coder army videp
	public:
	const int MOD = 1e9 + 7;

    int solve(int arr[], int n, int ind, int sum, vector<vector<int>>& dp) {
        
        // Base case: if we've considered all elements
        // since we can have 0 so check if sum == 0 only when you have seen all the array elements
        if (ind == n) {
            if(sum == 0)
                return 1;
            return 0;
        }
        
        if(ind > n || sum < 0)
            return 0;

        // Check if result is already computed
        if (dp[ind][sum] != -1) {
            return dp[ind][sum];
        }


        int notTake = solve(arr, n, ind + 1, sum, dp) % MOD;
        int take = solve(arr, n, ind + 1, sum - arr[ind], dp) % MOD;

        dp[ind][sum] = (take + notTake) % MOD;
        return dp[ind][sum];
    }

    int perfectSum(int arr[], int n, int sum) {
        // Edge case: if sum is negative, no subsets can make up the sum
        if (sum < 0) return 0;

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(arr, n, 0, sum, dp);
    }
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends