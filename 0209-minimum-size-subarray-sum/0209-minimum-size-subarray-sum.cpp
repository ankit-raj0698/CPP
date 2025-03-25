class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, sum = 0;
        int minlen = 1e9;

        while(right < nums.size()){

            sum += nums[right];

            while(left <= right && sum >= target){
                minlen = min(minlen, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return minlen == 1e9 ? 0 : minlen;
    }
};