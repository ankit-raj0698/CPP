class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int key = nums[i];

            if(mp.count(key) > 0){
                int j = mp[key];
                if(abs(i - j) <= k)
                    return true;
            }

            mp[key] = i;
        }
        return false; 
    }
};