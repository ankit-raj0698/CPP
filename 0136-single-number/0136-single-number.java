class Solution {
    public int singleNumber(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        for(int ele: nums){
            freq.put(ele, freq.getOrDefault(ele,0) + 1);
        }

        for(Integer key : freq.keySet()){
            if(freq.get(key) == 1)
                return key;
        }
        return 0;
    }
}