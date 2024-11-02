//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

int src;
int n;

int tsp(vector<vector<int>> &cost, int mask, int currCity, vector<vector<int>> &dp){
    // base case
    if(mask == ((1 << n ) - 1)){
        return cost[currCity][src];
    }
    if(dp[mask][currCity] != -1)
        return dp[mask][currCity];
    int ans = INT_MAX;
    // explore all cities from curr city
    for(int i = 0; i < n; i++){
        // if ith city is not visited
        if((mask & (1 << i)) == 0){
            int newAns = cost[currCity][i] + tsp(cost, mask | (1 << i), i, dp);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][currCity] = ans;
}
int total_cost(vector<vector<int>>cost){
    // Code here
    n = cost.size();
    vector<vector<int>> dp(1<<n, vector<int>(n, -1));
    // send mask as 0001 i.e src is visited and src node
    int mask = 0000;
    src = 0;
    mask = mask | (1 << src); // to mark the src node as visited
    
    return tsp(cost, mask, src, dp);
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends