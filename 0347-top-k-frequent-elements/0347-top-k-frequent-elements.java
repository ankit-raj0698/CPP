class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int n = nums.length;
        Map<Integer,Integer> freq = new HashMap<>();
        for(int ele: nums)
            freq.put(ele, freq.getOrDefault(ele,0) + 1);
        
        List<Integer>[] bucket = new List[n+1];
        for(int i = 0; i < n+1; i++)
            bucket[i] = new ArrayList<>();

        for(Map.Entry<Integer, Integer> entry: freq.entrySet())
            bucket[entry.getValue()].add(entry.getKey());

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