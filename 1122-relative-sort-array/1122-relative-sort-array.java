class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        
        int[] freq = new int[1001];
        int[] ans = new int[arr1.length];

        for(int ele: arr1)
            freq[ele]++;

        int k = 0;
        for(int ele: arr2){
            while(freq[ele]-- > 0)
                ans[k++] = ele;
        }

        for(int i = 0; i <= 1000; i++){
            while(freq[i]-- > 0)
                ans[k++] = i;
        }

        return ans;
    }
}