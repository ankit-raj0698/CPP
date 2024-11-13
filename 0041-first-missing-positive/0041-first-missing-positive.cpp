class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int ele = nums[i];

            if(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[ele - 1]){
                swap(nums[i], nums[ele-1]);
                i--;
            }
        }

        for(int i = 0;  i < n; i++){
            if(nums[i] != i+1)
                return i+1;
        }
        return n + 1;
    }
};