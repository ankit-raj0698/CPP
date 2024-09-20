class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // when vector size is less than or equal to 2, return its size
        if(nums.size() <= 2)
            return nums.size();

        // since we don't care what is present in first two position
        // start the pointer from third index
        // k is the position where new element will be inserted
        // compare element at index i with element at index k-2
        int i = 2, k = 2;
        while(i < nums.size()){
            if(nums[i] == nums[k-2])
                i++;
            else{
                nums[k] = nums[i];
                k++;
                i++;
            }
        }
        
        return k;
    }
};