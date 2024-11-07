class Solution {
public:
    int mod = 1e9 + 7;
    int dp[51][101][52];
    int solve(int n, int m, int k, int ind, int lastMax, int searchCost){

        // invalid state, no need of further recursion
        if(searchCost > k)
            return 0;
        
        // we have filled all the elements of array with values 1 .... m
        if(ind == n){
            // when searchcost = k, so we found a way
             if(searchCost == k)
                return 1;
            return 0;
        }

        if(dp[ind][lastMax][searchCost] != -1)
            return dp[ind][lastMax][searchCost];

        int ans = 0;
        for(int x = 1; x <= m; x++){
            if(x > lastMax) //curr element greater than prev max, increase the search cost
                ans = (ans + solve(n, m , k, ind + 1, x, searchCost+1)) % mod;
            else // curr element is less than prev max element 
                ans = (ans + solve(n, m, k, ind + 1, lastMax,searchCost))  % mod;
            
        }
        return dp[ind][lastMax][searchCost] = ans % mod;
    }
    int numOfArrays(int n, int m, int k) {
        
        memset(dp, -1, sizeof(dp));
        return solve(n, m, k, 0, 0, 0);
    }
};