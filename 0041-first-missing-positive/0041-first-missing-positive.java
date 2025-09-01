import java.util.*;
class Solution {
    public int firstMissingPositive(int[] nums) {

        int n = nums.length;
        boolean[] seen = new boolean[n+1];
        Arrays.fill(seen, false);
        
        for(int i = 0; i < n; i++){
            int ele = nums[i];
            if(ele > 0 && ele <= n)
                seen[ele] = true;
        }

        for(int i = 1; i <= n; i++){
            if(seen[i] == false)
                return i;
        }

        return n+1;
    }
}