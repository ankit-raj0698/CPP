class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        int maxFreq=INT_MIN;
        unordered_map<int,int> count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
            maxFreq=max(maxFreq,count[nums[i]]);
            if(maxFreq > 1){
                return true;
            }
        }
      return false;  
    }
};