class Solution {
public:
    /*
    create a map , iterate through the input array
    increment the count of element of array in map
    if count of any element is greater than 1 return false    
    */
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