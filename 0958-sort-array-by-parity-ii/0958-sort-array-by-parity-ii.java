class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        int evenInd = 0, oddInd = 1;
        int[] ans = new int[nums.length];

        for(int i = 0; i < nums.length; i++){
            if(nums[i] % 2 == 0){
                ans[evenInd] = nums[i];
                evenInd += 2;
            }
            else{
                ans[oddInd] = nums[i];
                oddInd += 2;
            }
        }
        return ans;
    }
}