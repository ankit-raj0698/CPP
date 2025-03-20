//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for(int i = 0; i < n ; i++)
            dp[i][i] = 0;
            
        for(int l = 2; l < n; l++){
            for(int i = 1; i <= n - l; i++){
                int j = i + l - 1;
                dp[i][j] = 1e9;
                
                for(int k = i; k < j; k++){
                    int cost = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        return dp[1][n-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends