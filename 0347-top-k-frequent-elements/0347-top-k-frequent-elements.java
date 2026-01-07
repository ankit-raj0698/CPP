class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int n = nums.length;
        // find the freq of each element
        Map<Integer,Integer> freq = new HashMap<>();
        for(int ele: nums)
            freq.put(ele, freq.getOrDefault(ele,0) + 1);
        
        // declare and initialize the array where each ind contains list of integer
        List<Integer>[] bucket = new List[n+1];
        for(int i = 0; i < n+1; i++)
            bucket[i] = new ArrayList<>();

        // populate the bucket (freq : ind, element with that freq is in list)
        for(Map.Entry<Integer, Integer> entry: freq.entrySet())
            bucket[entry.getValue()].add(entry.getKey());

        // iterate through the bucket array of list of integers
        // store most freq k elements in ans array
        int[] ans = new int[k];
        int ind = 0;
        for(int i = n; i >= 0 && ind < k; i--){
            if(!bucket[i].isEmpty()){
                for(int j = 0; j < bucket[i].size(); j++){
                    ans[ind++] = bucket[i].get(j);
                    if(ind == k)
                        return ans;
                }           
            }
        }
        return ans;
    }
}