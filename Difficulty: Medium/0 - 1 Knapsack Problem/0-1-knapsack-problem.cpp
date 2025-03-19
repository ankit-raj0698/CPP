//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dp[1001][1001];
    int solve(int W, vector<int> &val, vector<int> &wt, int ind){
        if(ind < 0)
            return 0;
            
        if(dp[W][ind] != -1)
            return dp[W][ind];
        
        int not_pick = solve(W, val, wt, ind - 1);
        int pick = 0;
        if(wt[ind] <= W)
            pick = val[ind] + solve(W - wt[ind], val, wt, ind - 1);
        
        return dp[W][ind] = max(pick, not_pick);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(W, val, wt, val.size() - 1);
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends