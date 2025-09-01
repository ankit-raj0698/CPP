import java.util.*;
class Solution {

    public void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public int firstMissingPositive(int[] nums) {
       int n = nums.length;
       int i = 0;

       while(i < n){
        int correctInd = nums[i] - 1;
        // nums[i] != nums[correctInd] to handle infinite loop in [1,1] test case
        if(nums[i] > 0 && nums[i] <= n && nums[i] != nums[correctInd])
            swap(nums, i, correctInd);
        else
            i++;
       }

       for(i = 0; i < n; i++){
        if(nums[i] != i+1)
            return i + 1;
       }

       return n+1;
    }
}