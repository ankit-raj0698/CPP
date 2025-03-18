class Solution {
public:
    bool check(vector<int>& nums,int mid){
        // if mid is the last element of array, then it is peak
        if(mid == nums.size()-1)
            return true;
        
        if(nums[mid] > nums[mid + 1])
            return true;
        
        return false;
    }
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(nums,mid)){
                ans = mid;
                high = mid -1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};