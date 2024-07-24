//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solve(vector<vector<int>>& points,int day, int lastTask,
                    vector<vector<int>> &dp){
        // base case
        if(day == 0){
            int maxi = 0;
            for(int i = 0; i < 3; i++){
                if(i != lastTask)
                    maxi = max(maxi,points[0][i]);
            }
            return  dp[day][lastTask] = maxi;
        }
        if(dp[day][lastTask] != -1)
            return dp[day][lastTask];
        // recurrence relation
        int maxi = 0;
        for(int i = 0; i < 3; i++){
            if(i != lastTask){
                int res = points[day][i] + solve(points, day - 1, i,dp);
                maxi = max(maxi, res);
            }
        }
        return dp[day][lastTask] = maxi; 
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int> (4,-1));
        return solve(points,n-1,3,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends