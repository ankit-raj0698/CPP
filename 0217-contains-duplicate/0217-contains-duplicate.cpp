class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int ele:nums){
            count[ele]++;
            if(count[ele] > 1)
                return true;
        }
        return false;
    }
};