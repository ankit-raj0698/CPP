class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long maxi = INT_MIN;

        long long prefix = 1, suffix = 1;
        for(int i = 0; i < n; i++){
            prefix = nums[i] * prefix;
            suffix = nums[n - i - 1] * suffix;

            maxi = max({maxi, prefix, suffix});

            if(prefix == 0)
                prefix = 1;
            if(suffix == 0)
                suffix = 1;
        }
        return maxi;
    }
};