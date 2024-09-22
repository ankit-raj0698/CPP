class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0 , right = 0, prod = 1, ans = 0;

        if(k == 0)
            return 0;
        
        while(right < nums.size()){
            prod *= nums[right];

            while(left <= right && prod >= k)
                prod /= nums[left++];
            
            // to count no. of contiguous subarray at window ending at right pointer
            // it is window size
            if(prod < k)
                ans += (right - left + 1);
            
            right++;
        }
        return ans;
    }
};