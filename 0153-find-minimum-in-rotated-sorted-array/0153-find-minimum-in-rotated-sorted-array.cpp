class Solution {
public:
    bool check(vector<int>& nums, int mid){
        if(nums[0] > nums[mid])
            return true;
        return false;
    }
    int findMin(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        if(nums[0] < nums[n-1])
            return nums[0];

        int low = 0, high = n-1;
        int ans = -1;
        while(low <= high){

            int mid = low + (high - low)/2;
            if(check(nums, mid)){
                ans = mid;
                high = mid - 1;
            }
            else 
                low = mid + 1;
        }
        return nums[ans];
    }
};