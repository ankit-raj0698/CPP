class Solution {
public:
    
    int getPivot(vector<int>& nums){
        
        int start=0;
        int end=nums.size()-1;
        
        while(start < end){
            int mid=start+(end-start)/2;
            if(nums[mid] >= nums[0]){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        return start;
        
    }
    
    int binarySearch(vector<int>& nums,int start,int end,int target){
        int ans=-1;
        while(start <= end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                ans=mid;
                return ans;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
        
    
    int search(vector<int>& nums, int target) {
        int end=nums.size()-1;
        int ans=-1;
        int pivot=getPivot(nums);
        //cout<<pivot;
        if(pivot==-1){
            ans=binarySearch(nums,0,end,target);
        }
        
        if(nums[pivot]==target){
            return pivot;
        }
        else if(nums[0] <= target){
            ans=binarySearch(nums,0,pivot-1,target);
        }
        else{
            ans=binarySearch(nums,pivot+1,end,target);
        }
       return ans; 
    }
};