import java.util.*;
class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {
        NavigableSet<Long> set = new TreeSet<>();

        for(int i = 0; i < nums.length; i++){
            Long ele = (long) nums[i];
            Long ceil = set.ceiling(ele);
            Long floor = set.floor(ele);

            if(floor != null && Math.abs(floor - ele) <= valueDiff)
                return true;

            if(ceil != null && Math.abs(ceil - ele) <= valueDiff)
                return true;
            
            set.add(ele);
            if(set.size() > indexDiff)
                set.remove((long) nums[i-indexDiff]);
        }
        return false;
    }
}