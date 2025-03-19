class Solution {
public: 
    int dp[101];
    int solve(vector<int> &nums, int startIndex, int ind, vector<int> &dp){
        if(ind == startIndex)  
            return nums[ind];
        if(ind < startIndex)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int notTake = solve(nums, startIndex, ind - 1, dp);
        int take = solve(nums, startIndex, ind - 2, dp) + nums[ind];

        return dp[ind] = max(notTake, take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        return max(solve(nums, 0, n-2, dp1), solve(nums, 1, n-1, dp2));
        
    }
};