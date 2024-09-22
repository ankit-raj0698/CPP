class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;
        int left = 0, right = 0, sum = 0, maxLen = -1;

        while(right < nums.size()){
            sum += nums[right];

            while(left <= right && sum > target)    
                sum -= nums[left++];
            
            if(sum == target)
                maxLen = max(maxLen, right - left + 1);

            right++;
        }

        if(maxLen != -1)
            return nums.size() - maxLen;
        
        // when we can't have any element whose sum is x
        return -1;
        
    }
};