class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int closestSum = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < n - 2; i++){
            int j = i + 1;
            int k = n - 1;

            while(j < k){
                int currSum = nums[i] + nums[j] + nums[k];
                if(Math.abs(currSum - target) < Math.abs(closestSum - target))
                    closestSum = currSum;

                if(currSum == target){
                    return currSum;
                }
                else if(currSum < target)
                    j++;
                else 
                    k--;
            }
        }
        return closestSum;
    }
}