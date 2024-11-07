class Solution {
public:
    
    int solve(vector<int>& nums, int  ind, int sum, vector<vector<long>> &dp){
        if(ind < 0){
            if(sum % 3 == 0)
                return 0;
            return -1e9;
        }

        if(dp[ind][sum] != -1)
            return dp[ind][sum];

        int not_take = solve(nums, ind - 1, sum, dp);
        int take = nums[ind] + solve(nums, ind - 1, (sum + nums[ind])% 3, dp);

        return dp[ind][sum] = max(not_take , take);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        //long long sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<long>> dp(n, vector<long>(3, -1));
        return  solve(nums, n-1, 0, dp);
    }
};