class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the first index of the element from right 
        // such that nums[i] < nums[i+1]
        int ind = -1;
        int n = nums.size();
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }

        // if ind != -1 then find the first index of the element from right 
        // such that nums[i] > nums[ind]
        int swap_ind = ind;
        if(ind != -1){
            for(int i = n-1; i >= 0; i--){
                if(nums[i] > nums[ind]){
                    swap_ind = i;
                    break;
                }
            }

        // swap nums[ind], nums[swap_ind]
        swap(nums[ind], nums[swap_ind]);

        }

        // reverse the array from ind + 1 till end
        reverse(nums.begin() + ind + 1, nums.end());  

              
    }
};