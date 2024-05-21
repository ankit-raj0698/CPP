class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        
        if(n < 3){
            return ans;
        }
        
        for(int i = 0; i < n; i++){
            
            if( i > 0 && nums[i] == nums[i-1]){
                        continue;
                    }
            
            int target = -nums[i];
            int j = i + 1;
            int k = n - 1;
            
            while(j < k){
                if(nums[j] + nums[k] < target){
                    j++;
                }
                else if(nums[j] + nums[k] > target){
                    k--;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while( j < k && nums[j] == nums[j-1]){
                        j++;
                    }
                    
                    while( j < k && nums[k] == nums[k+1]){
                        k--;;
                    }
                }
            }
        }
        return ans;
    }
};