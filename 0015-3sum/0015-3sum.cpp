class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();
        if(n <= 2)
            return ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n-2; i++){
            int target = -nums[i];

            // handle duplicates for i
            if(i-1 >= 0 && nums[i] == nums[i-1])
                continue;
            
            int j = i + 1;
            int k = n - 1;

            while(j < k){
                int sum = nums[j] + nums[k];
                if(sum == target){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // handle duplicates for j
                    while(j < k && nums[j] == nums[j - 1])
                        j++;
                    
                    // handle duplicates for k
                    while(j < k && nums[k] == nums[k + 1])
                        k--;

                }
                else if(sum < target)
                    j++;
                else 
                    k--;
            }

        }
       return ans; 
    }
};