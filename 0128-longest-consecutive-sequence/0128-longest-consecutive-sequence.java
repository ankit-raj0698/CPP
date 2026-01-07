class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for(int ele: nums)
            set.add(ele);
        
        int ans = 0;
        Iterator<Integer> it = set.iterator();
        while(it.hasNext()){
            int val = it.next();
            int count = 1;
            if(!set.contains(val - 1)){
                while(set.contains(val + 1)){
                    count++;
                    val++;
                }               
            }
            ans = Math.max(ans, count);
        }
        return ans;
    }
}