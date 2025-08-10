class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        int len = nums.length;
        int evenInd = 0, oddInd = 1;
        while(evenInd < len && oddInd < len){
            if(nums[evenInd] % 2 == 0) // evenInd -> even
                evenInd += 2;
            else if(nums[oddInd] % 2 == 1) // oddInd -> odd
                oddInd += 2;
            else // evenInd -> odd && oddInd -> even
            {
                int temp = nums[evenInd];
                nums[evenInd] = nums[oddInd];
                nums[oddInd] = temp;

                evenInd += 2;
                oddInd += 2;
            }         
        }
        return nums;
    }
}