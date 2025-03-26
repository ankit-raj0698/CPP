class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();

        for(int ele: nums){
            mp[ele]++;
        }

        // for(auto [key, value]: mp){
        //     if(value > (n/3))
        //         ans.push_back(key);
        // }

        for(auto i: mp){
            if(i.second > (n/3))
                ans.push_back(i.first);
        }
        return ans;    
        
    }
};