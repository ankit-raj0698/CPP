class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++){
            // find the last bit if it is 1 or 0
            // reduce the curr no to half
            dp[i] = (i % 2) + dp[i / 2];
        }
        return dp;
    }
};