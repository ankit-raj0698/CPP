class Solution {
public:
    int dp[301][5001];
    int solve(vector<int>& coins, int amount, int ind){
        if(ind < 0){
            return amount == 0;
        }

        if(dp[ind][amount] != -1)
            return dp[ind][amount];
        
        int not_pick = solve(coins, amount, ind - 1);
        int pick = 0;
        if(coins[ind] <= amount)
            pick = solve(coins, amount - coins[ind], ind);
        
        return dp[ind][amount] = pick + not_pick;
        
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        return solve(coins, amount, n-1);
    }
};