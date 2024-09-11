class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> count;
        
        for(auto ele: nums){
           count[ele]++;
            if(count[ele] > 1)
                return true;
        }
        return false;
    }
};