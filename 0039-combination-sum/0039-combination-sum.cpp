class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& candidates, int target, int ind, vector<int> &temp){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        /*
        if(target < 0 || ind == candidates.size())
            return;
        
        // exclude the current element
        solve(candidates, target, ind + 1, temp);
        // include the current element
        temp.push_back(candidates[ind]);
        solve(candidates, target - candidates[ind], ind, temp);
        temp.pop_back();
        */
        for(int i = ind; i < candidates.size(); i++){
            // include the current element
            if(candidates[i] <= target){
            temp.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i, temp);
            temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates, target, 0, temp);
        return res;
    }
};