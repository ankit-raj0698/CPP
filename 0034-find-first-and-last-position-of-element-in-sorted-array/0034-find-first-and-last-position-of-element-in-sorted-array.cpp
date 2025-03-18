class Solution {
public:
    bool leftCheck(vector<int>& nums, int target, int mid){
        if(nums[mid] >= target)
            return true;
        return false;
    }

    bool rightCheck(vector<int>& nums, int target, int mid){
        if(nums[mid] <= target)
            return true;
        return false;
    }

    int leftOccurrence(vector<int>& nums, int target){
        int start=0;
        int end=nums.size()-1;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(leftCheck(nums, target, mid)){
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        if(ans != -1 && nums[ans] != target)
            return -1;

        return ans;
    }

    int rightOccurrence(vector<int>& nums, int target){
        int start=0;
        int end=nums.size()-1;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(rightCheck(nums, target, mid)){
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        if(ans != -1 && nums[ans] != target)
            return -1;
            
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int left=leftOccurrence(nums,target);
        int right=rightOccurrence(nums,target);
        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }
};