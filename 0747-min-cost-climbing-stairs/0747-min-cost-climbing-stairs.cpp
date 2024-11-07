class Solution {
public:
    int n;
    int dp[1001];
    int solve(vector<int>& cost, int ind){
        if(ind >= n)
            return 0;

        if(dp[ind] != -1)
            return dp[ind];
        
        int one_step = cost[ind] + solve(cost, ind + 1);
        int two_step = cost[ind] + solve(cost, ind + 2);

        return dp[ind] = min(one_step, two_step);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        memset(dp, -1, sizeof(dp));
        return min(solve(cost,0), solve(cost, 1));
    }
};