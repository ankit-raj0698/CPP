//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  int n;
    bool solve(vector<int>& arr, int ind, int sum, vector<vector<int>> &dp){
        if(ind < 0){
            return sum == 0;
        }
        
        if(dp[ind][sum] != -1)
            return dp[ind][sum];
        
        bool not_take = solve(arr, ind - 1, sum, dp);
        bool take = false;
        if(arr[ind] <= sum)
            take = solve(arr, ind - 1, sum - arr[ind], dp);
        
        return dp[ind][sum] = not_take || take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(arr, n-1, sum, dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends