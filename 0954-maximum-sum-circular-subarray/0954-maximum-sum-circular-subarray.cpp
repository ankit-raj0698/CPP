class Solution {
public:
    int minSumKadane(vector<int>& nums){
        // find the min sum subarray using kadane algo
        int sum = 0;
        int minSum = INT_MAX;  
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            minSum = min(minSum, sum);  

            if (sum > 0)  // Reset the sum if it exceeds 0
                sum = 0;
        }
        return minSum;
    }

    int maxSumKadane(vector<int>& nums){
        int sum = 0;
        int maxSum = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            maxSum = max(maxSum, sum);

            if(sum < 0)
                sum = 0;
        }
        return maxSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int minSum = minSumKadane(nums);
        int maxSum = maxSumKadane(nums);
        int maxSumRotated = totalSum - minSum;

        // if we are returning max(maxSum, maxSumRotated) then we need to handle one edge case
        // [-1, -2, -3]
        // total sum = -6, minSum = -6, maxsum = -1
        // maxSumRotated = -6 -(-6) = 0
        // max(maxSum, maxSumRotated) would be 0 which is wrong
        // so to handle this return max(maxSum, maxSumRotated) only when maxSum > 0
        // otherwise return maxSum
        


        return maxSum > 0 ? max(maxSum, maxSumRotated) : maxSum;
        
    }
};