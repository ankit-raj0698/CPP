class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;
        int lessThanCnt = 0;
        int equalCnt = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] < pivot)
                lessThanCnt += 1;
            else if(nums[i] == pivot)
                equalCnt += 1;
        }

        int[] ans = new int[n];
        int low = 0, mid = lessThanCnt, high = lessThanCnt + equalCnt;
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot)
                ans[low++] = nums[i];
            else if(nums[i] == pivot)
                ans[mid++] = nums[i];
            else
                ans[high++] = nums[i];
        }
        return ans;
    }
}