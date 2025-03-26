class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target)
                return true;
            
            // for duplicates in rotated sorted array
            // we have to case where nums[low] = nums[mid] = nums[high]

            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }       

            // check if first half is sorted
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
       return false; 
    }
};