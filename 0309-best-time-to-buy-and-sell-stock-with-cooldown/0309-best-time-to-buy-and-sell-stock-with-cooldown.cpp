class Solution {
public:
    int n;
    int dp[5001][3];
    int solve(vector<int>& prices, int ind, int buy){
        if(ind >= n)
            return 0;
        
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + solve(prices, ind + 1, 0), solve(prices, ind + 1, 1));
        }
        else{
            profit = max(prices[ind] + solve(prices, ind + 2, 1), solve(prices, ind + 1, 0));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 1);
        
    }
};