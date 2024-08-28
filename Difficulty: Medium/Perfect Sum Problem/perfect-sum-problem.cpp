//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int MOD = 1e9 + 7;
class Solution{

	public:
	int solve(int arr[], int ind, int target, vector<vector<int>>& dp) {
    

    if (ind <0)
        return target == 0 ? 1 : 0;

    
    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTaken = solve(arr, ind - 1, target, dp) % MOD;

    int taken = 0;
    if (arr[ind] <= target)
        taken = solve(arr,ind - 1, target - arr[ind], dp)  % MOD;

    return dp[ind][target] = (notTaken + taken)  % MOD;
    }

    int perfectSum(int arr[], int n, int sum) {
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return solve(arr,n - 1, sum,dp);
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