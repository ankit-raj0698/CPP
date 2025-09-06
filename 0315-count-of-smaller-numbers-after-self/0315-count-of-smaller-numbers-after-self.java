class Solution {

    public void merge(int[][] pair, int low, int mid, int high, int[] count){
        int n = mid - low + 1;
        int m = high - mid;

        int[][] left = new int[n][2];
        int[][] right = new int[m][2];

        for(int i = 0; i < n; i++)
            left[i] = pair[low + i];
        
        for(int j = 0; j < m; j++)
            right[j] = pair[mid + 1 + j];

        int i = 0, j = 0, k = low;
        while(i < n && j < m){
            if(left[i][0] > right[j][0]){
                count[left[i][1]] += (m - j);
                pair[k++] = left[i++];
            }
            else
                pair[k++] = right[j++];
        }

        while(i < n)
            pair[k++] = left[i++];
        while(j < m)
            pair[k++] = right[j++];
    }

    public void mergeSort(int[][] pair, int low, int high, int[] count){
        if(low >= high)
            return;
        
        int mid = low + (high - low)/2;
        
        mergeSort(pair, low, mid, count);
        mergeSort(pair, mid+1, high, count);
        merge(pair, low, mid, high, count);
    }
    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        int[][] pair = new int[n][2];

        for(int i = 0; i < n; i++){
            pair[i][0] = nums[i];
            pair[i][1] = i;
        }

        int[] count = new int[n];
        mergeSort(pair, 0, n -1, count);

        List<Integer> result = new ArrayList<>();
        for (int c : count) result.add(c);
        return result;
    }
}