class Solution {
public:
    
    int solve(vector<int>& nums, int  ind, int rem, vector<vector<int>> &dp){
        if(ind < 0){
            if(rem % 3 == 0)
                return 0;
            return -1e9;
        }

        if(dp[ind][rem] != -1)
            return dp[ind][rem];

        int not_take = solve(nums, ind - 1, rem, dp);
        int take = nums[ind] + solve(nums, ind - 1, (rem + nums[ind])% 3, dp);

        return dp[ind][rem] = max(not_take , take);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return  solve(nums, n-1, 0, dp);
    }
};