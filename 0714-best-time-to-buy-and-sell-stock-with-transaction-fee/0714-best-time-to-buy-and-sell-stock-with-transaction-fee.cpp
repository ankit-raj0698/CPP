class Solution {
public:
    int n;
    int dp[50001][3];
    int solve(vector<int>& prices, int ind, int buy, int fee){
        if(ind >= n)
            return 0;
        
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + solve(prices, ind + 1, 0, fee), solve(prices, ind + 1, 1, fee));
        }
        else{
            profit = max(prices[ind]  - fee + solve(prices, ind + 1, 1, fee), solve(prices, ind + 1, 0, fee));
        }
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 1, fee);
        
    }
};