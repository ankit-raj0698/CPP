class Solution {
    public int majorityElement(int[] nums) {
        int ans = 0, count = 0;
        for(int ele: nums){
            if(count == 0){
                ans = ele;
            }
            count += (ans == ele) ? 1 : -1;
        }
        return ans;
    }
}