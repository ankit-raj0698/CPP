class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        
        Map<Integer, Integer> freq = new HashMap<>();
        List<Integer>[] buckets = new List[nums.length + 1];
        int[] ans = new int[k];

        // 1. Frequency count
        for (int num : nums)
            freq.put(num, freq.getOrDefault(num, 0) + 1);

        // 2. Fill buckets (lazy initialization)
        for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            int f = entry.getValue();
            if (buckets[f] == null)
                buckets[f] = new ArrayList<>();
            buckets[f].add(entry.getKey());
        }

        // 3. Collect top k from highest frequency
        int idx = 0;
        for (int i = buckets.length - 1; i >= 0 && idx < k; i--) {
            if (buckets[i] == null) continue;
            for (int num : buckets[i]) {
                ans[idx++] = num;
                if (idx == k)
                    return ans;
            }
        }
        return ans;
    }
}