//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dp[10001][101];
    int solve(vector<int> &arr, int ind, int k){
        if(ind == 0)
            return 0;
        
        if(dp[ind][k] != -1)
            return dp[ind][k];
        
        int minSteps = 1e9;
        for(int j = 1; j <= k; j++){
            if(ind - j >= 0){
                int jump = abs(arr[ind] - arr[ind - j]) + solve(arr, ind - j, k);
                minSteps = min(minSteps, jump);
            }
        }
        return dp[ind][k] = minSteps;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(arr, n-1, k);
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends