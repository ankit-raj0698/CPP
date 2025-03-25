class Solution {
public:
    int dp[301][301];
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        memset(dp, 0, sizeof(dp));

        // l denotes length
        for(int l = 1; l <=n; l++){
            // i goes from to 0 to last valid row
            for(int i = 0; i <= n-l; i++){
                // l = j - i + 1
                int j = i  + l - 1;
                // k can be anything from i to j
                for(int k = i; k <=j; k++){
                    // when k == i then dp[i][i-1] which is invalid so handle it
                    int left = i == k ? 0 : dp[i][k-1];
                    // when k == j then dp[j+1][j] which is invalid so handle it
                    int right = j == k ? 0 : dp[k+1][j];

                    // handle out of bound case for i and j
                    int val = (i == 0 ? 1 :nums[i-1]) * nums[k] * (j == n-1 ? 1 : nums[j+1]);

                    dp[i][j] = max(dp[i][j], left + val + right);
                }
            }
        }

// return first row last col val
        return dp[0][n-1];      
    }
};