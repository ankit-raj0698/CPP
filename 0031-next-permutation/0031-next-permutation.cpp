class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;

        // find the ind from right where nums[i] < nums[i+1]
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }

        // find the ind of the element from right which is greater than nums[ind]
        // swap this with nums[ind]
        if(ind != -1){
            for(int i = n-1; i > ind; i--){
                if(nums[i] > nums[ind]){
                    swap(nums[i], nums[ind]);
                    break;
                }
            }
        }

        // reverse the array from ind + 1 till end
        reverse(nums.begin() + ind + 1, nums.end());
        
    }
};