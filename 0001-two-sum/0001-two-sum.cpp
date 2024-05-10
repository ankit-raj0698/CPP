class Solution {
public:
    /*
    to store the answer create a vector , to store the elements create an unordered_map 
    iterate through the input array , find the remainder i.e.. (target - sum)
    if remainder is present in map so two sum exists , update the answer vector with index       of remainder and index of the current element
    else insert the current element in map
        (key -> element , value -> index of the current element)
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            
            int rem = target - nums[i];
            
            if(mp.count(rem)){
                ans.push_back(mp[rem]);
                ans.push_back(i);
            }
            else{
                mp[nums[i]]=i;
            }
        }
        return ans;
        
    }
};