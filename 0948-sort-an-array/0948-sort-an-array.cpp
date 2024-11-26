class Solution {
public:
    int partition(vector<int> &nums, int start, int end){
        int pos = start;

        // whatever no is less than equal to last element, swap it with pos
        for(int i = start; i < end; i++){
            if(nums[i] <= nums[end]){
                swap(nums[i], nums[pos]);
                pos++;
            }
        }
        // put the pivot element at correct pos
        swap(nums[pos], nums[end]);
        return pos;
    }
    void quicksort(vector<int> &nums, int start, int end){
        // base case : 0 or 1 element left
        if(start >= end)
            return;
        
        int pivot = partition(nums, start, end); // find the pivot index
        quicksort(nums, start, pivot-1); // left part
        quicksort(nums, pivot+1, end); // right part
    }

    void merge(vector<int> &nums, int start, int mid, int end){
        int n = mid - start + 1;
        int m = end - mid;

        vector<int> left(n);
        vector<int> right(m);

        for(int i = 0; i < n; i++)
            left[i] = nums[start + i];

        for(int i = 0; i < m; i++)
            right[i] = nums[mid + 1 + i];

        int i = 0, j = 0, k = start;
        while(i < n && j < m){
            if(left[i] <= right[j])
                nums[k++] = left[i++];
            else
                nums[k++] = right[j++];
        }

        while(i < n)
            nums[k++] = left[i++];
        while(j < m)
            nums[k++] = right[j++];
    }


    void mergesort(vector<int> &nums, int start, int end){
        if(start == end)
            return;
        int mid = start + (end - start)/2;
        mergesort(nums, start, mid);
        mergesort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {

        int start = 0, end = nums.size()-1;
        //quicksort(nums, start, end);
        mergesort(nums, start, end);
        return nums;
        
    }
};