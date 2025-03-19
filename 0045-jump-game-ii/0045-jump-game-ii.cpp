class Solution {
public:
    int n;
    int dp[10001];
    int solve(vector<int>& nums, int ind){
        if(ind >= n-1)
            return 0;

        if(dp[ind] != -1)
            return dp[ind];
        
        int k = nums[ind];
        int minJump = 1e9;
        for(int j = 1; j <= k; j++){
            if(ind + j <= n-1){
                int jump = solve(nums, ind + j);
                minJump = min(minJump, jump + 1);
            }
                
        }
        return dp[ind] = minJump;
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};