class Solution {
    public int findDuplicate(int[] nums) {

        // initially both slow and fast points to head i.e. nums[0]
        int slow = nums[0];
        int fast = nums[0];

        // there is a cycle when slow == fast but this is also our initial condition 
        // so increment slow and fast one time 
        slow = nums[slow];
        fast = nums[nums[fast]];

        // at the end of while loop , slow and fast points to same element so there is a cycle
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // find start of the cycle to get the duplicate element
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
}