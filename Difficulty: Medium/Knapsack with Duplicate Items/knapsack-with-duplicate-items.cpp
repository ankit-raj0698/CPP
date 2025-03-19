//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    
    int dp[1001][1001];
    int solve(vector<int>& val, vector<int>& wt, int capacity, int ind){
        
        if(ind < 0)
            return 0;
        
        if(dp[ind][capacity] != -1)
            return dp[ind][capacity];
        
        int not_pick = solve(val, wt, capacity, ind - 1);
        int pick = 0;
        if(wt[ind] <= capacity)
            pick = val[ind] + solve(val, wt, capacity - wt[ind], ind);
        
        return dp[ind][capacity] = max(pick, not_pick);
    }
    
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        memset(dp, -1, sizeof(dp));
        return solve(val, wt, capacity, n-1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends