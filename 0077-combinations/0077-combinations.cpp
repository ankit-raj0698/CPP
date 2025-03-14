class Solution {
public:
    vector<vector<int>> res;
    void solve(int start, int n, int k, vector<int> &temp){

        // when we got k elements in our temp ans
        if(k == 0){
            res.push_back(temp);
            return;
        }

        /*
        // we have explored all n elements
        if(start > n)
            return;

        // exclude the current element
        solve(start + 1, n, k, temp);

        // include the current element
        temp.push_back(start);
        solve(start + 1, n, k - 1, temp);
        temp.pop_back();
        */

        for(int i = start; i <= n; i++){
            // include the current element
            temp.push_back(i);
            solve(i + 1, n, k - 1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;

        solve(1, n, k, temp);

        return res;
        
    }
};