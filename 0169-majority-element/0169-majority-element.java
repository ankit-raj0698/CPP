class Solution {
    public int majorityElement(int[] nums) {
       Map<Integer, Integer> freq = new HashMap<>();
       int n = nums.length;
       for(int ele: nums){
            freq.put(ele, freq.getOrDefault(ele,0) + 1);
            if(freq.get(ele) > (n/2))
                return ele;
       }
       return 0; 
    }
}