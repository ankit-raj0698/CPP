class Solution {
public:
    int minimumCost(vector<int>& nums) {
        /*int n = nums.size();
        int minSum = INT_MAX;
        for(int j = 1; j < n - 1; j++){
            for(int k = j + 1; k < n; k++){
                int sum = nums[0] + nums[j] + nums[k];
                minSum = min(sum, minSum);
            }
        }
       return minSum; 
       */
        
        sort(nums.begin() + 1, nums.end());
        return nums[0] + nums[1] + nums[2];
    }
};