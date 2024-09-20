class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        if(n < 4)
            return ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 3; i++){

            // handle duplicates for i
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            
            for(int j = i + 1; j < n - 2; j++){

                // handle duplicates for j
                if(j > i+1 && nums[j] == nums[j - 1])
                    continue;
                
                long long newTarget = (long long)target;
                newTarget -= nums[i];
                newTarget -= nums[j];

                int k = j + 1;
                int l = n - 1;

                while(k < l){
                    long long sum = (long long)nums[k];
                    sum += nums[l];
                    if(sum == newTarget){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        // handle duplicates for k
                        while(k < l && nums[k] == nums[k - 1])
                            k++;
                        
                        // handle duplicates for l
                        while(k < l && nums[l] == nums[l + 1])
                            l--;

                    }
                    else if(sum < newTarget)
                        k++;
                    else
                        l--;
                }
            }
        }
        return ans;
    }
};