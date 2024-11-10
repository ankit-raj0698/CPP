class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX, n = nums.size();

        for(int i = 0; i < n; i++){
            int orsum = 0;
            for(int j = i; j < n; j++){
                orsum |= nums[j];
                if(orsum >= k)
                    ans = min(ans, j - i + 1);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};