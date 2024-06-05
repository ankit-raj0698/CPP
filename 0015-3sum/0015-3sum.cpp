class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        
        if(n < 3){
            return ans;
        }
        
        for(int i = 0; i < n-2; i++){
            //made mistake here by using a while loop in place of if block
            if( i > 0 && nums[i] == nums[i-1]){
                        continue;
                    }
            
            int target = -nums[i];
            int j = i + 1;
            int k = n - 1;
            
            //Apply two sum concept
            while(j < k){
                
                int sum = nums[j] + nums[k];
                
                if( sum < target ){
                    j++;
                }
                else if( sum > target){
                    k--;
                }
                else{
                    //push the triplet in ans
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    
                    //handle duplicate elements for index j
                    while( j < k && nums[j] == nums[j-1]){
                        j++;
                    }
                    //handle duplicate elements for index k
                    while( j < k && nums[k] == nums[k+1]){
                        k--;;
                    }
                }
            }
        }
        return ans;
    }
};