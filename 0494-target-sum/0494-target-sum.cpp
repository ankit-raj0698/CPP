class Solution {
public:
    int dp[21][2001];
    int countTargetSum(vector<int>& nums, int target, int ind){

        if(ind < 0)
            return target == 0;
        
        if(dp[ind][target] != -1)
            return dp[ind][target];

        int notTake = countTargetSum(nums, target, ind - 1);
        int take = 0;
        if(nums[ind] <= target)
            take = countTargetSum(nums, target - nums[ind], ind - 1);
        
        return dp[ind][target] = take + notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        int sum  = accumulate(nums.begin(), nums.end(), 0);
        if(sum - target < 0 || (sum - target) % 2 != 0)
            return 0;
        
        int newTarget = (sum - target)/2;
        return countTargetSum(nums, newTarget, nums.size()-1);
        
    }
};