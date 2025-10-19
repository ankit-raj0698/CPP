class Solution {
    public void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public int[] sortArrayByParityII(int[] nums) {
        int oddInd = 1, evenInd = 0;
        int size = nums.length;

        while(oddInd < size && evenInd < size){
            if(nums[evenInd] % 2 != 0){
                while(oddInd < size && nums[oddInd] % 2 != 0)
                    oddInd += 2;
                swap(nums, evenInd, oddInd);
            }
            evenInd += 2;
        }
        return nums;
    }
}