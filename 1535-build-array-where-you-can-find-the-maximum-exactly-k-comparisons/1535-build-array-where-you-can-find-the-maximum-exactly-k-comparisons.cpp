class Solution {
public:
    int mod = 1e9 + 7;
    int dp[51][101][52];
    int solve(int n, int ind, int m, int lastMax, int k, int searchCost){

        if(searchCost > k)
            return 0;

        if(ind == n){
             if(searchCost == k)
                return 1;
            return 0;
        }

        if(dp[ind][lastMax][searchCost] != -1)
            return dp[ind][lastMax][searchCost];

        int ans = 0;
        for(int x = 1; x <= m; x++){
            if(x > lastMax)
                ans = (ans + solve(n, ind + 1, m, x, k, searchCost+1)) % mod;
            else   
                ans = (ans + solve(n, ind + 1, m, lastMax, k, searchCost))  % mod;
            
        }
        return dp[ind][lastMax][searchCost] = ans % mod;
    }
    int numOfArrays(int n, int m, int k) {
        
        memset(dp, -1, sizeof(dp));
        return solve(n, 0, m, 0, k, 0);
    }
};