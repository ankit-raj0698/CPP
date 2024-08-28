//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
    int solve(vector<vector<int>>& arr, int day, int lastTask,vector<vector<int>> &dp){
        // base case
        if(day == 0){
             int maxi = 0;
            // find max points from the 3 tasks
            for(int i = 0; i < 3; i++){
                //only select the task that is not done on prev day
                if(i != lastTask)
                    maxi = max(maxi, arr[0][i]);
        }
        return dp[day][lastTask] = maxi;
    }
        
        if(dp[day][lastTask] != -1){
            return dp[day][lastTask];
        }
        
        
        // recurrence relation
        int maxi = 0;
        // recursive call over all the 3 tasks
        for(int i = 0; i < 3; i++){
            //only select the task that is not done on prev day
            if(i != lastTask){
                int res = arr[day][i] + solve(arr, day - 1, i,dp);
                maxi = max(maxi, res);
            }
        }
        
        return dp[day][lastTask] = maxi;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return solve(arr,n-1,3,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends