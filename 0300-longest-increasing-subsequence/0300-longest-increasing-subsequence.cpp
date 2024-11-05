class Solution {
public:
    int n;
    int dp[2501][2502];
    int solve(vector<int>& nums, int ind, int prev_ind){
        if(ind >= n)
            return 0;
        
        if(dp[ind][prev_ind + 1] != -1)
            return dp[ind][prev_ind + 1];
        
        int not_take = solve(nums, ind + 1, prev_ind);
        int take = 0;
        if(prev_ind == -1 || nums[ind] > nums[prev_ind])
            take = 1 + solve(nums, ind + 1, ind);

        return dp[ind][prev_ind + 1] = max(take, not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
        
    }
};