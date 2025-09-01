class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] freq = new int[1001];
        int[] ans = new int[arr1.length];
        Arrays.sort(arr1);

        for(int ele: arr1)
            freq[ele]++;
        
        int i = 0;
        Set<Integer> set = new HashSet<>();
        for(int ele: arr2){
            while(freq[ele]-- > 0){
                ans[i++] = ele;
            }
            set.add(ele);
        }

        for(int ele: arr1){
            if(!set.contains(ele))
                ans[i++] = ele;
        }

        return ans;
    }
}