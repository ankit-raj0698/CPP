class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, sum = 0, ans = INT_MAX;
        while(right < nums.size()){
            sum += nums[right];

            while(left <= right && sum >= target){
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
            right++;
        }
        if(ans == INT_MAX)
            return 0;
        return ans;
    }
};