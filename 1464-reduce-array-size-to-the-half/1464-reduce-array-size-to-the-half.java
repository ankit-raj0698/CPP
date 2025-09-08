import java.util.*;
class Solution {
    public int minSetSize(int[] arr) {
        
        Map<Integer, Integer> freq = new HashMap<>();
        for(int ele: arr){
            freq.put(ele, freq.getOrDefault(ele,0) + 1);
        }

        // create max heap on freq
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> (freq.get(b) - freq.get(a)));
        //pq.addAll(freq.keySet());
        for(Map.Entry<Integer,Integer> entry: freq.entrySet())
            pq.add(entry.getKey());
        
        int len = arr.length, half = arr.length/2;
        int ans = 0;
        while(len > half){
            ans++;
            len = len - freq.get(pq.poll());
        }

        return ans;
    }
}