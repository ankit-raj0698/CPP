class Solution {
public:

    int solve(vector<int> &nums, int ind, int Xor){
        if(ind >= nums.size())
            return Xor;
        
        int exclude = solve(nums, ind + 1, Xor);
        int include = solve(nums, ind + 1, Xor ^ nums[ind]);

        return exclude + include;
    }
    int subsetXORSum(vector<int>& nums) {

        return solve(nums, 0, 0);
        
    }
};