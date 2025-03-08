class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target)
                return mid;
            
            // check if array from low to mid is sorted
            if(nums[low] <= nums[mid]){
                // check if target is in this half
                if(nums[low] <= target && target <= nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // second half is sorted
            else{
                // check if target is in this half
                if(nums[mid] <= target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};