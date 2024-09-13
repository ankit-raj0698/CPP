class Solution {
public:

// using extra array to store prefix sum
    /*
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n);

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            prefixSum[i] = sum;
        }

        for(int i = 0; i < n; i++){
            int leftSum = (i == 0) ? 0 : prefixSum[i - 1];
            int rightSum = prefixSum[n - 1] - leftSum - nums[i];

            if(leftSum == rightSum)
                return i;
        }
        return -1;
    }
    */

    int pivotIndex(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum, rightSum, prefixSum = 0;

        for(int i = 0; i < nums.size(); i++){
            leftSum = prefixSum;
            rightSum = totalSum - leftSum - nums[i];

            if(leftSum == rightSum)
                return i;
            
            prefixSum += nums[i];
        }
        return -1;
    }
};