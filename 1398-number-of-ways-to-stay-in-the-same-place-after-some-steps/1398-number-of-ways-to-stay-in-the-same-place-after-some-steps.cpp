class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int steps, int arrLen, int ind, int pos, vector<vector<int>> &dp){

        if(pos < 0 || pos >= arrLen)
            return 0;
        
        if(steps == ind){
            if(pos == 0)
                return 1;
            return 0;
        }

        if(dp[ind][pos] != -1)
            return dp[ind][pos] % mod;

        int left = solve(steps, arrLen, ind + 1, pos - 1, dp) % mod;
        int right = solve(steps, arrLen, ind + 1, pos + 1 , dp)  % mod;
        int stay = solve(steps, arrLen, ind + 1, pos, dp)  % mod;

        return dp[ind][pos] = ((left + right)  % mod + stay)  % mod;

    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps + 1, vector<int>(steps + 1, -1));
        return solve(steps, arrLen, 0, 0, dp);
    }
};