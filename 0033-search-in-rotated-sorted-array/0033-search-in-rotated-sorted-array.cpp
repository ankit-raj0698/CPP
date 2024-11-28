class Solution {
public:
    bool check(vector<int>& nums, int mid){
        if(nums[mid] < nums[0])
            return true;
        return false;
    }

    int getPivot(vector<int>& nums){
        int low = 0, high = nums.size()-1;
        int ans = 0;
        while(low  <= high){
            int mid = low + (high - low)/2;
            if(check(nums, mid)){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
       return ans; 
    }

    int binarySearch(vector<int> &nums, int target, int low , int high){

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target)
                return mid;           
            else if(target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
       int pivotIndex =  getPivot(nums);
    
        cout << "pivot index = " << pivotIndex << endl;
        if(pivotIndex == 0)
            return binarySearch(nums, target, 0, nums.size() - 1);
            
       if(nums[pivotIndex] == target)
            return pivotIndex;
        
        
        
        if(target < nums[0])
            return binarySearch(nums, target, pivotIndex + 1, nums.size() - 1);
        else 
            return binarySearch(nums, target, 0, pivotIndex - 1);
            

    }
};