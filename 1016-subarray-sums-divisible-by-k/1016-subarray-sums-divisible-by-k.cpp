class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(); 
        int sum = 0, ans = 0;
        
        // {rem -> count}
        unordered_map<int, int> mp; 
        mp[0] = 1;
        
        for(int i = 0; i < n; i++){
            
            // calculate the prefix sum
            sum += nums[i];
            
            // find the remainder
            // int rem = sum % k;
            // if(rem < 0)
            //     rem = rem + k;
            
            int rem = (sum % k + k) % k;
            
            // when rem is present in map , update ans
            if(mp.find(rem) != mp.end())
                ans += mp[rem];
            
            // otherwise update the count of rem in map
            mp[rem]++;
        }
        
        return ans;
    }
};