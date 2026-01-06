class Solution {

    class Pair<U,V>{
        U first;
        V second;
        Pair(U first, V second){
            this.first = first;
            this.second = second;
        }
    }

    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        PriorityQueue<Pair<Integer,Integer>> pq = new PriorityQueue<>((a,b) -> Integer.compare(a.first,b.first));
        int[] ans = new int[k];
        for(int ele: nums)
            freq.put(ele, freq.getOrDefault(ele, 0) + 1);
        
        for(Map.Entry<Integer, Integer> entry: freq.entrySet()){
            pq.offer(new Pair(entry.getValue(), entry.getKey()));
            if(pq.size() > k)
                pq.poll();
        }
        int i = 0;
        while(!pq.isEmpty()){
            ans[i++] = pq.poll().second;
        }
        return ans;
    }
}