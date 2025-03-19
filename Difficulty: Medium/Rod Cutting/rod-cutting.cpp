//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int dp[1001][1001];
    int solve(vector<int> &price, int ind, int capacity){
        
        if(ind < 0)
            return 0;
        
        if(dp[ind][capacity] != -1)
            return dp[ind][capacity];
        
        int not_pick = solve(price, ind - 1, capacity);
        int length = ind + 1;
        int pick = 0;
        if(length <= capacity)
            pick = price[ind] + solve(price, ind, capacity - length);
        
        return dp[ind][capacity] = max(pick, not_pick);
            
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        memset(dp, -1, sizeof(dp));
        return solve(price, n-1, n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends