class Solution {
public:
    int dp[13][10001];
    int solve(vector<int>& coins, int amount, int ind){
        if(ind < 0){
            if(amount == 0)
                return 0;
            return 1e9;
        }

        if(dp[ind][amount] != -1)
            return dp[ind][amount];
        
        int not_pick = solve(coins, amount, ind - 1);
        int pick = 1e9;
        if(coins[ind] <= amount)
            pick = 1 + solve(coins, amount - coins[ind], ind);
        
        return dp[ind][amount] = min(pick,not_pick);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(coins, amount, n-1);

        return ans == 1e9 ? -1 : ans;
    }
};