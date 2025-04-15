class Solution {
public:
    int solve(vector<int>& nums, int target, int low, int high){
        int mid = low + (high - low)/2;
        while(low <= high){
            if(nums[mid] == target)
                return mid;
            else if(target < nums[mid])
                return solve(nums, target, low, mid - 1);
            else 
                return solve(nums, target, mid + 1, high);
        }      
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        return solve(nums, target, low, high);
    }
};