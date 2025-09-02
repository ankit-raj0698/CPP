class Solution {
    static int cnt;
    
    static void merge(int[] arr, int low, int mid, int high){
        int n = mid - low + 1;
        int m = high - mid;
        
        int[] left = new int[n];
        int[] right = new int[m];
        
        for(int i = 0; i < n; i++)
            left[i] = arr[low + i];
            
        for(int j = 0; j < m; j++)
            right[j] = arr[mid + 1 + j];
            
        int i = 0, j = 0, k = low;
        while(i < n && j < m){
            if(left[i] <= right[j])
                arr[k++] = left[i++];
            else{
                cnt += n - i;
                arr[k++] = right[j++];
            }
        }
        
        while(i < n)
            arr[k++] = left[i++];
        while(j < m)
            arr[k++] = right[j++];
        
    }
    
    static void mergeSort(int[] arr, int low, int high){
        if(low >= high)
            return;
        
        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
    static int inversionCount(int arr[]) {
        // Code Here
        int low = 0, high = arr.length - 1;
        cnt = 0;
        mergeSort(arr, low, high);
        return cnt;
    }
}