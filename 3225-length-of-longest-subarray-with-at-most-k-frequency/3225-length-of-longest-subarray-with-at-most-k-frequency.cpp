class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int left = 0, right = 0, ans = INT_MIN;
        while(right < nums.size()){
            mp[nums[right]]++;

            while(mp[nums[right]] > k){
                mp[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};