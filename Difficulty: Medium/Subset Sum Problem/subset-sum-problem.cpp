//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = true;
        
        for(int j = 1; j <= sum; j++)
            dp[0][j] = false;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                
                // always fill dp table based on immediate above row
                // exclude : here j is sum
                if(arr[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                
                // include : here j is sum
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
                    
            }
        }
        return dp[n][sum];
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