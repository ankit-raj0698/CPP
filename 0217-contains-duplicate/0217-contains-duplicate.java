class Solution {
    public boolean containsDuplicate(int[] nums) {
        Map<Integer, Integer> seen = new HashMap<>();
        for(int ele: nums){
            seen.put(ele,seen.getOrDefault(ele,0) + 1);
            if(seen.get(ele) > 1)
                return true;
        }
        return false;
    }
}