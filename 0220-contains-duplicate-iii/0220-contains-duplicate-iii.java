import java.util.*;
class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {
        NavigableSet<Long> set = new TreeSet<>();
        for(int i = 0; i < nums.length; i++){
            Long ele = (long)nums[i];
            Long floor = set.floor(ele);
            Long ceiling = set.ceiling(ele);

            if(floor != null && Math.abs(ele - floor) <= valueDiff)
                return true;
            
            if(ceiling != null && Math.abs(ele - ceiling) <= valueDiff)
                return true;
            
            set.add(ele);
            if(set.size() > indexDiff)
                set.remove((long)nums[i-indexDiff]);
        }
        return false;
    }
}