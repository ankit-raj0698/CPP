class Solution {
    public int singleNumber(int[] nums) {
        // int ans = 0;
        // for(int ele: nums){
        //     ans ^= ele;
        // }
        // return ans;
        Set<Integer> set = new HashSet<>();
        for(int ele: nums){
            if(set.contains(ele))
                set.remove(ele);
            else
                set.add(ele);
        }
        return set.iterator().next();
    }
}