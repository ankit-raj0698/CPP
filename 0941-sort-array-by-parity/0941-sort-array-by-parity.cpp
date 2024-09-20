class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = -1;
        while(i < nums.size()){
            if(nums[i] % 2 == 0){
                j++;
                swap(nums[i], nums[j]);
            }
            i++;
        }
        return nums;
    }
};