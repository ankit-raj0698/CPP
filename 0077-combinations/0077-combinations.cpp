class Solution {
public:
    void solve(int start, int n, int k, vector<int> &temp, vector<vector<int>> &res){
        
        

        if(k == 0){
            res.push_back(temp);
            return;
        }

        if(start > n)
            return;

        solve(start + 1, n, k, temp, res);
        temp.push_back(start);
        solve(start + 1, n, k - 1, temp, res);
        temp.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        int start = 1;
        vector<int> temp;
        vector<vector<int>> res;

        solve(start, n, k, temp, res);

        return res;
        
    }
};