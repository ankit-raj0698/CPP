class Solution {
    private:
    int getPivot(vector<int>& nums,int start,int end){
        while(start < end){
            int mid=start+(end-start)/2;
            if(nums[mid]>=nums[0]){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        
        return start;
    }
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        if(nums[start]<=nums[end]){
            return nums[start];
        }
        int pivot=getPivot(nums,start,end);
        return nums[pivot];

    }
};