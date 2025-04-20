class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        int prefixSum = 0;
        mp[prefixSum]++;

        // we are following the prefix sum concept
        // prefixsum[right] - prefixsum[left - 1] = k
        // that is prefixsum[right] - k = prefixsum[left - 1]
        // we are checking at each index ending at right
        // how many occurrences of prefixsum[right] - k is present
        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];

            if(mp.find(prefixSum - k) != mp.end())
                ans += mp[prefixSum - k];
            
            mp[prefixSum]++;
        }
        return ans;
    }
};