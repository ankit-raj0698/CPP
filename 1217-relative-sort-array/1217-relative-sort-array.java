import java.util.*;

class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int len = arr1.length;
        int[] ans = new int[len];

        // find the freq of arr1
        SortedMap<Integer,Integer> freq = new TreeMap<>();
        for(int ele: arr1){
            freq.put(ele, freq.getOrDefault(ele,0) + 1);
        }

        // custom sort on basis of arr2
        int k = 0;
        for(int ele: arr2){
            int n = freq.get(ele);
            for(int i = 0; i < n; i++){
                ans[k++] = ele;
            }
            freq.remove(ele);
        }

        // put rest of the elements in sorted order
        for(Map.Entry<Integer,Integer> entry: freq.entrySet()){
            int n = entry.getValue();
            for(int i = 0; i < n; i++){
                ans[k++] = entry.getKey();
            }
        }
        return ans;
    }
}