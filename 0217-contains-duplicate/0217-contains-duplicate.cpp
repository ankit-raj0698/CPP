class Solution {
public:
    /*
    create an unordered map , iterate through the input array
    find the frequency of every element of array using map
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