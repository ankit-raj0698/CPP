class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for(int ele: nums){
            if(seen.contains(ele))
                return true;
            seen.add(ele);         
        }
        return false;
    }
}