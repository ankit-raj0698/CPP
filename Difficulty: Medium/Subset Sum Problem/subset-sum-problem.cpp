//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool solve(vector<int>arr, int ind, int target, vector<vector<int>> &dp){
        // base case on target & index
        if(target == 0)
            return true;
        
        if(ind == 0)
            return (arr[0] == target);
            
        if(dp[ind][target] != -1 )
            return dp[ind][target] ;
        
        //  not_take & take recursive call
            
        bool not_take = solve(arr, ind-1, target, dp);
        bool take = false;
        if(arr[ind] <= target)
            take = solve(arr, ind-1, target - arr[ind] , dp);
        
        return dp[ind][target] =  (not_take) || (take);
        
        
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        bool res = solve(arr, n-1, sum,dp);
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends