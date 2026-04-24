class Solution {
public:
    int findDuplicate(vector<int>& nums) {

         // initially both slow and fast points to head i.e. nums[0]
        int slow = nums[0];
        int fast = nums[0];
        
        // there is a cycle when slow == fast but this is also our initial condition 
        // so increment slow and fast one time 
        slow = nums[slow];
        fast = nums[nums[fast]];
        
        // at the end of while loop , slow and fast points to same element so there is a cycle
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        // find start of the cycle to get the duplicate element
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
    
    
    /*
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();      
        unordered_map<int,int> mp;
        for(int val: nums){
            mp[val]++;
            if(mp[val] > 1)
                return val;
        }
        return -1;
    }
    
    int findDuplicate(vector<int>& nums) { 
        int index = nums[0];
        while(true){
            if(nums[index] < 0)
                return index;
            else
                nums[index] = -nums[index];
            index = abs(nums[index]);
        }
        return -1;
    }
    */
};