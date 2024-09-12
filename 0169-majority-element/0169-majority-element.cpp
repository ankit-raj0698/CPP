class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // find the candidate
        int candidate = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(count == 0){
                candidate = nums[i];
                count = 1;
            }
            else if(nums[i] == candidate)
                count++;
            else 
                count--;
        }

        // verify the candidate if it is majority element
        count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == candidate)
                count++;
        }
        if(count > nums.size()/2)
            return candidate;
        
        return -1;
        
    }

// brute force
    /*
        int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;

        for(auto ele: nums){
            count[ele]++;
            if(count[ele] > nums.size() / 2)
                return ele;
        }
        return -1;
    }
    */
};