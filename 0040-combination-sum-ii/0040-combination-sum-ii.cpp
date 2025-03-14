class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& nums, int target, int ind, vector<int> &temp){
        if(target == 0){
            res.push_back(temp);
            return;
        }

        if(target < 0 || ind >= nums.size())
            return;
        

        for(int i = ind; i < nums.size(); i++){
            // handle duplicate elements
            if(i > ind && nums[i] == nums[i-1])
                continue;
            // include current element
            if(nums[i] <= target){
                temp.push_back(nums[i]);
                solve(nums, target - nums[i], i + 1, temp);
                temp.pop_back();
            }          
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, temp);
        return res;
        
    }
};