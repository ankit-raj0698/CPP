class Solution {
public:
    // brute force(O(n*n))
    /*
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j <  n; j++){
                if(nums[i] == nums[j])
                    count++;
            }
        }
       return count; 
    }
    */

    // using hashmap
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> count;
        for(int ele: nums)
            count[ele]++;

        for(auto it: count){
            int val = it.second;
            // total no. of permutation will be val * (val - 1)
            // but since we have to maintain i < j condition
            //  we divide by 2 to maintain above condition
            res += val * (val - 1)/2;
        }
        return res;
    }
};