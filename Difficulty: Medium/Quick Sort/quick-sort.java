class Solution {
    public void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public void quickSort(int[] arr, int low, int high) {
        // code here
        if(low >= high)
            return;
        
        int partitionInd = partition(arr, low, high);
        quickSort(arr, low, partitionInd - 1);
        quickSort(arr, partitionInd + 1, high);
        
    }

    private int partition(int[] arr, int low, int high) {
        
        // code here
        int pivot = arr[high];
        int i = low - 1;
        for(int j = low; j <= high - 1; j++){
            if(arr[j] <= pivot){
                i++;
                swap(arr, i, j);
            }
        }
        i++;
        swap(arr,i,high);
        return i;
    }
}