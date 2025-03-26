class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int prefix = 1, suffix = 1, maxi = -1e9;

        for(int i = 0; i < n; i++){
            prefix = prefix * nums[i];
            maxi = max(maxi, prefix);

            if(prefix == 0)
                prefix = 1;
        }

        for(int i = n-1; i >= 0; i--){
            suffix = suffix * nums[i];
            maxi = max(maxi, suffix);

            if(suffix == 0)
                suffix = 1;
        }
        return maxi;
    }
};