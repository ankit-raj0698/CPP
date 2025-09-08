class Solution {
    public void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    public int[] sortArrayByParityII(int[] nums) {
        int evenInd = 0, oddInd = 1;
        int n = nums.length;
        
        // find indices when nums[evenInd] = odd and nums[oddInd] = even then swap them
        while(evenInd < n && oddInd < n){
            if(nums[evenInd] % 2 != 0){ // odd at even index
                while(oddInd < n && nums[oddInd] % 2 != 0){ // skips odd at odd index
                    oddInd += 2;
                }
                // swap wrong indices
                swap(nums, evenInd, oddInd);
            }
            evenInd += 2;
        }
        return nums;
    }
}