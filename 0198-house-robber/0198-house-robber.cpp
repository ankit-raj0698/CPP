class Solution {
public:
    int dp[101];
    int solve(vector<int> &nums, int ind){
        if(ind == 0)
            return nums[ind];
        
        if(ind < 0)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int notTake = solve(nums, ind - 1);
        int take = solve(nums, ind - 2) + nums[ind];

        return dp[ind] =  max(take, notTake);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, n-1);
    }
};