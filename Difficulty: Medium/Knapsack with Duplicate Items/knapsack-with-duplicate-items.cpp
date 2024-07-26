//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int solve(int val[], int wt[], int ind, int bagwt, vector<vector<int>> &dp){
        
        if(ind == 0){
            return (bagwt/wt[ind])*val[ind];
        }  
        
        if(dp[ind][bagwt] != -1)
            return dp[ind][bagwt];
        
        int not_take = 0 + solve(val, wt, ind - 1, bagwt, dp);
        int take = INT_MIN;
        if(wt[ind] <= bagwt)
            take = val[ind] + solve(val, wt, ind, bagwt - wt[ind], dp);
        
        return dp[ind][bagwt] = max(take , not_take);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(W+1, -1));
        int ans = solve(val, wt,N-1,W,dp);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends