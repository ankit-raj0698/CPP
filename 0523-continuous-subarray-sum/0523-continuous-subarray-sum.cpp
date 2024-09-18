class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;

        // mp[0] = -1 to handle case when entire array sum is divisible by k
        // [1,2,3] k = 6
        mp[0] = -1;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int rem = sum % k;

            // when rem is in map , check length of subarray
            if(mp.count(rem) > 0){
                if(i - mp[rem] >= 2)
                    return true;
            }
            // when rem is not in map, then only update the index
            // don't overwrite the index
            else 
                mp[rem] = i;

        }
        return false;
    }
};