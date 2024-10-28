class Solution {
public:
    int n;
    vector<vector<int>> dp;
    bool solve(vector<int>& nums, int ind, int target){

        // handle base case for 1 element
        if(ind == 0){
            if(target == nums[ind])
                return true;
            return false;
        }

        if(dp[ind][target] != -1)
            return dp[ind][target];
        
        // explore all options
        bool not_take = solve(nums, ind - 1, target);
        bool take = false;
        if(nums[ind] <= target)
            take = solve(nums, ind - 1, target - nums[ind]);

        return dp[ind][target] = not_take || take;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2 == 1)
            return false;
        
        dp.resize(n, vector<int>((sum/2 + 1), -1));
        return solve(nums, n - 1, sum / 2);
    }
};