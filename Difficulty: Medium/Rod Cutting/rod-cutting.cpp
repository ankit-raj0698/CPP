//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int solve(int price[], int ind, int n, vector<vector<int>> &dp){
        
        if(ind == 0){
            return n*price[ind];
        }  
        
        if(dp[ind][n] != -1)
            return dp[ind][n];
        
        int not_take = 0 + solve(price, ind - 1, n, dp);
        int take = INT_MIN;
        int rodlen = ind + 1;
        if(rodlen <= n)
            take = price[ind] + solve(price, ind, n - rodlen, dp);
        
        return dp[ind][n] = max(take , not_take);
    }
    
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1, -1));
        int ans = solve(price,n-1,n,dp);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends