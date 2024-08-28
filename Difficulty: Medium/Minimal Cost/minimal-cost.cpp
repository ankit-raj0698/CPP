//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int solve(vector<int>& height, int ind, int n, vector<int>& dp, int k){
        if(ind == n - 1)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
            
        int minsteps = INT_MAX;
        
        for(int j = 1; j <= k; j++){
            
            if(ind + j < n){
                int jump = solve(height, ind + j, n, dp, k) + abs(height[ind] - height[ind + j]);
                minsteps = min(minsteps, jump);
            }
            
        }
           
        return dp[ind] = minsteps;
            
    }
    
    int minimizeCost(vector<int>& arr, int& k) {
        
        // Code here
        int n = arr.size();
        vector<int> dp(n,-1);
        
        return solve(arr, 0, n, dp, k);
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
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends