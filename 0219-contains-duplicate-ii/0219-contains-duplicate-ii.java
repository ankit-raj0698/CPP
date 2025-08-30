class Solution {

    public boolean containsNearbyDuplicate(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();

        for(int i = 0; i < n; i++){
            if(mp.containsKey(nums[i]) && Math.abs(i - mp.get(nums[i])) <= k)
                return true;
            
            mp.put(nums[i], i);
            //System.out.println(mp);
        }

        return false;
    }
}