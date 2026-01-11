class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int sum = (n * (n+1))/2;
        int currSum = 0;
        for(int ele: nums)
            currSum += ele;
        
        return (sum - currSum);
    }
}