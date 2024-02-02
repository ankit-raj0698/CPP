class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int i=0,j=0;
        while(j<nums.size()){
            //when ele is not equal to val swap with nums[i]
            if(nums[j]!=val){
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }
        return i;
    }
};