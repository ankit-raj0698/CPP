class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;

        int left = 0, right = 0, count = 0, n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        while(right < nums.size()){
            if(nums[right] == maxi)
                count++;
            
            while(count >= k){
                ans += n - right;
                // shrink the window
                if(nums[left] == maxi)
                    count--;
                left++;
            }
            right++;
        }
        return ans;
    }
};