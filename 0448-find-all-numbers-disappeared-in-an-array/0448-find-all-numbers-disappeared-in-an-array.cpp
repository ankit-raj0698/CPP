class Solution {
public:
 
    // count the freq of each element
    /*
        vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n + 1, 0);
        vector<int> result;
        for(int ele: nums)
            count[ele]++;
        
        for(int i = 1; i <= n; i++){
            if(count[i] == 0)
                result.push_back(i);
        }
        return result;
    }
    */

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        // put each element of nums to their correct position
        // 1 -> 0th index, 2 -> 1st index, 3 -> 2nd index
        // 1 -> nums[0], 2 -> nums[1], 3 -> nums[2]
        // 1 -> nums[1 - 1], 2 -> nums[2 - 1] etc..

        for(int ele: nums){
            while(ele != nums[ele - 1])
                swap(ele, nums[ele - 1]);
        }
        for(int i = 1; i <= nums.size(); i++){
            if(i != nums[i - 1])
                ans.push_back(i);
        }
        return ans;
    }
};