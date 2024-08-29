//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    
    int solve(int W, int ind, vector<int>& wt, vector<int>& val, vector<vector<int>> &dp){
        if(ind >= wt.size())
            return 0;
            
        if(dp[ind][W] != -1)
            return dp[ind][W];
        
        if(wt[ind] <= W){
            int notTake = solve(W, ind + 1, wt, val, dp);
            int take = val[ind] + solve(W - wt[ind], ind + 1, wt, val, dp);
            return dp[ind][W] = max(take, notTake);
        }
        else{
            return dp[ind][W] = solve(W, ind + 1, wt, val, dp);
        }
    }
    
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        if(W == 0)
            return 0;
        
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W + 1,-1));
        return solve(W, 0, wt, val, dp);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends