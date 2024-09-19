class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1)
            return 0;

        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int left = 0, right = 0;
        while(right < nums.size()){
            while(right - left + 1 > k){
                left++;
            }
            if(right - left + 1 == k)
                ans = min(ans, nums[right] - nums[left]);
            right++;
        }

        return ans;
        
    }
};