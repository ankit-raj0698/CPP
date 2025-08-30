class Solution {

    public boolean containsNearbyDuplicate(int[] nums, int k) {
        int n = nums.length;
        //Map<Integer, Integer> mp = new HashMap<>();
        Set<Integer> set = new HashSet<>();

        for(int i = 0; i < n; i++){
            // if(mp.containsKey(nums[i]) && Math.abs(i - mp.get(nums[i])) <= k)
            //     return true;          
            // mp.put(nums[i], i);
            
            if(set.contains(nums[i]))
                return true;
            
            set.add(nums[i]);
            if(set.size() > k)
                set.remove(nums[i-k]);
        }

        return false;
    }
}