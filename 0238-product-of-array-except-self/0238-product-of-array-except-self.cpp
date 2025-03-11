class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int prodWithoutZero = 1;
        int countNonZero = 0;
        for(auto ele: nums){
            prod *= ele;
            if(ele != 0){
                countNonZero++;
                prodWithoutZero *= ele;
                }
        }

        int zeroCount = nums.size() - countNonZero;
        vector<int> ans(nums.size(),0);
        if(zeroCount > 1)
            return ans;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0)
                ans[i] = prod/nums[i];
            else
                ans[i] = prodWithoutZero;             
        }
        return ans;
    }
};