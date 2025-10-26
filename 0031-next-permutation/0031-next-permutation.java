class Solution {
    public void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public void reverse(int[] nums, int low, int high){
        while(low < high){
            swap(nums, low, high);
            low++;
            high--;
        }
    }
    public void nextPermutation(int[] nums) {
        int ind = -1;
        int n = nums.length;
        // find first ind from right side such that nums[i] < nums[i + 1]
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                ind = i;
                break;
            }
        }

        if(ind != -1){
            // find ind of the no. just greater than nums[ind] from (n - 1) till (ind + 1)
            for(int i = n - 1; i > ind; i--){
                if(nums[i] > nums[ind]){
                    swap(nums, ind, i);
                    break;
                }
            }
        }    
        reverse(nums, ind + 1, n - 1);  
    }
}