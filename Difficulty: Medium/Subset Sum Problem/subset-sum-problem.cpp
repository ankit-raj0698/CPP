//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool solve(vector<int>arr, int ind, int sum, vector<vector<int>> &dp){
        
        if(sum ==  0)
            return true;
        
        if(ind >= arr.size() || sum < 0)
            return false;
            
        

            
        if(dp[ind][sum] != -1 )
            return dp[ind][sum] ;
            
        
        
            
        bool not_pick = solve(arr, ind + 1, sum, dp);
        bool pick = solve(arr, ind + 1, sum - arr[ind], dp);
        
        return dp[ind][sum] = not_pick || pick;
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1,-1));
        return solve(arr, 0, sum, dp);
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