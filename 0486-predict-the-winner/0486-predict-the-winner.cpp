class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int i, int j){
        if(i >  j)
            return 0;

        if(i == j)
            return nums[i];
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int take_i = nums[i] + min(solve(nums, i+2, j), solve(nums,i+1, j-1));
        int take_j = nums[j] + min(solve(nums, i+1, j-1), solve(nums, i, j-2));

        return dp[i][j] = max(take_i, take_j);

    }

    int recursiveApproach2(vector<int>& nums, int i, int j){
        if(i >  j)
            return 0;

        if(i == j)
            return nums[i];
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int take_i = nums[i] - recursiveApproach2(nums, i+1,j);
        int take_j = nums[j] - recursiveApproach2(nums, i,j-1);

        return dp[i][j] = max(take_i, take_j);

    }


    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<int>(n,-1));
        // int sum = accumulate(nums.begin(), nums.end(), 0);
        // int p1_score = solve(nums, 0, nums.size()-1);
        // int p2_score = sum - p1_score;

        // return p1_score >= p2_score;

        int p1_score = recursiveApproach2(nums, 0, nums.size()-1);
        return p1_score >= 0;




        
    }
};