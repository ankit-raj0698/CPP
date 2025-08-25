class Solution {
    
    void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    void selectionSort(int[] arr) {
        // code here
        for(int i = 0; i < arr.length; i++){
            int minInd = i;
            for(int j = i; j < arr.length; j++){
                if(arr[j] < arr[minInd])
                    minInd = j;
            }
            //System.out.println("minInd = " + minInd);
            // swap curr ind with min ind
            swap(arr, i, minInd);
        }
    }
}