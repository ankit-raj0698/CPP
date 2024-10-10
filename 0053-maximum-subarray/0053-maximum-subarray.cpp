class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int right = 0;
        int sum = 0;
        int maxSum = INT_MIN;
        
        while(right < nums.size()){

            sum += nums[right];
            maxSum = max(maxSum, sum);

            if(sum < 0){
                sum = 0;               
            }

            right++;
        }

        return maxSum;
    }
};