class Solution {
public:
    vector<vector<int>> res;
    void solve(int start, int end, int k, int target, vector<int> &temp){
        if(k == 0){
            if(target == 0)
                res.push_back(temp);
            return;
        }
        
        if(target < 0 || start > end)
            return;

        // exclude the current element
        solve(start + 1, end, k, target, temp);
        // include the current element
        temp.push_back(start);
        solve(start + 1, end, k - 1, target - start, temp);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       int start = 1;
       int end = 9;
       vector<int> temp; 
       solve(start, end, k, n, temp);
       return res;
    }
};