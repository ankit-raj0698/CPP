class Solution {
public:
    int n;
    int dp[1001][201];
    int solve(int k, vector<int>& prices, int ind, int tranNo){
        if(ind >= n || tranNo == 2 * k)
            return 0;
        
        if(dp[ind][tranNo] != -1)
            return dp[ind][tranNo];
            
        int profit =  0;
        if(tranNo % 2 == 0){
            profit = max(-prices[ind] + solve(k, prices, ind + 1, tranNo + 1),
                            solve(k, prices, ind + 1, tranNo));
        }
        else{
            profit = max(prices[ind] + solve(k, prices, ind + 1, tranNo + 1),
                            solve(k, prices, ind + 1, tranNo));
        }
        return dp[ind][tranNo] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(k, prices, 0, 0);
    }
};