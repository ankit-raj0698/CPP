class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int low, int high){
        if(low > high)
            return -1;
        
        int mid = low + (high - low)/2;
        if(nums[mid] == target)
            return mid;
        
        if(nums[low] <= nums[mid]){
            if(nums[low] <= target && target <= nums[mid])
                return binarySearch(nums, target, low, mid - 1);
            else
                return binarySearch(nums, target, mid+1, high);
        }
        else{
            if(nums[mid] <= target && target <= nums[high])
                return binarySearch(nums, target, mid + 1, high);
            else
                return binarySearch(nums, target, low, mid - 1);
        }
    }
    int search(vector<int>& nums, int target) {
        
        int low = 0, high = nums.size() - 1;
        return binarySearch(nums, target, low, high);

        // while(low <= high){
        //     int mid = low + (high - low)/2;

        //     if(nums[mid] == target)
        //         return mid;
            
        //     // check if array from low to mid is sorted
        //     if(nums[low] <= nums[mid]){
        //         // check if target is in this half
        //         if(nums[low] <= target && target <= nums[mid])
        //             high = mid - 1;
        //         else
        //             low = mid + 1;
        //     }
        //     // second half is sorted
        //     else{
        //         // check if target is in this half
        //         if(nums[mid] <= target && target <= nums[high])
        //             low = mid + 1;
        //         else
        //             high = mid - 1;
        //     }
        // }
        // return -1;
    }
};