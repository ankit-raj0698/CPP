class Solution {
public:
    int dp[301][301];
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        memset(dp, 0, sizeof(dp));

        for(int l = 1; l <=n; l++){
            for(int i = 0; i <= n-l; i++){
                int j = i  + l - 1;
                for(int k = i; k <=j; k++){
                    int left = i == k ? 0 : dp[i][k-1];
                    int right = j == k ? 0 : dp[k+1][j];

                    int val = (i == 0 ? 1 :nums[i-1]) * nums[k] * (j == n-1 ? 1 : nums[j+1]);

                    dp[i][j] = max(dp[i][j], left + val + right);
                }
            }
        }

        return dp[0][n-1];
        
    }
};