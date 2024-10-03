class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();
        // we are expecting nums will contain 1 ..... n
        for(int i = 0; i < n; i++){
            int ele = nums[i]; // map it with index ele - 1

            // consider only no. between 1 to n and ignore rest
            // when element is not at its correct index , move it to correct place
            if(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[ele - 1]){
                swap(nums[i], nums[ele - 1]);
                i--; // so that we again check the index after swap
            }
        }

        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1)
                return i + 1;
        }

        // when all no from 1 to n is present in that case return n + 1
        return n + 1;
        
    }
};