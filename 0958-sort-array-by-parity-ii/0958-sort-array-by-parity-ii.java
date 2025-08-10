class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        int[] even = new int[nums.length/2];
        int[] odd = new int[nums.length/2];
        int[] ans = new int[nums.length];

        int j = 0, k = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] % 2 == 0)
                even[j++] = nums[i];
            else
                odd[k++] = nums[i];
        }

        j = 0;
        k = 0;
        for(int i = 0; i < nums.length; i++){
            if(i % 2 == 0)
                ans[i] = even[j++];
            else
                ans[i] = odd[k++];
        }
        return ans;
    }
}