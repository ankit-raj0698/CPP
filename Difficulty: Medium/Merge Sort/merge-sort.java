class Solution {
    
    void merge(int[] arr, int low, int mid, int high){
        int n1 = mid - low + 1;
        int n2 = high - mid;
        
        int[] left = new int[n1];
        int[] right = new int[n2];
        
        for(int i = 0; i < n1; i++)
            left[i] = arr[low + i];
        
        for(int i = 0; i < n2; i++)
            right[i] = arr[mid + 1 + i];
        
        int i = 0, j = 0;
        int k = low;
            
        while(i < n1 && j < n2){
            if(left[i] <= right[j])
                arr[k++] = left[i++];
            else
                arr[k++] = right[j++];
            
        }
        
        while(i < n1)
            arr[k++] = left[i++];
        
        while(j < n2)
            arr[k++] = right[j++];
    }

    void mergeSort(int arr[], int l, int r) {
        // code here
        if(l >= r)
            return;
            
        int mid = l + (r - l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
        
    }
}