class Solution {
public:
    void merge(vector<int>& nums, int start, int mid, int end){
        // a[start ... mid]
        // b[mid + 1 ... end]
        // size = upper - lower + 1

        // declare size of left and right array
        int n = mid - start + 1;
        // end - (mid + 1) - 1
        int m = end - mid;

        vector<int> left(n);
        vector<int> right(m);

        // copy elements of original array to left and right array
        for(int i = 0; i < n; i++)
            left[i] = nums[start + i];
        
        for(int i = 0; i < m; i++)
            right[i] = nums[mid + 1 + i];

        // merge left and right array into original array
        int i = 0, j = 0, k = start;
        while(i < n && j < m){
            if(left[i] <= right[j]){
                nums[k++] = left[i++];
            }
            else
                nums[k++] = right[j++];
        }

        while(i < n)
            nums[k++] = left[i++];
        while(j < m)
            nums[k++] = right[j++];

    }

    void mergeSort(vector<int>& nums, int start, int end){
        if(start < end){
            int mid = start + (end - start)/2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            merge(nums, start, mid, end);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};