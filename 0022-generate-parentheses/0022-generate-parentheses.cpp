class Solution {
public:
    void solve(int n, int open, int close, string res, vector<string> &ans){

        if(open == close && open == n){
            ans.push_back(res);
            return;
        }

        // when no. of open bracket is less than n, then we can push open bracket in res
        if(open < n)
            solve(n, open + 1, close, res + '(', ans);
        
        // when no. of close bracket is less than open,then we can push open bracket in res
        if(close < open)
            solve(n, open, close + 1, res + ')', ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        // n, openBracket count, closeBracket count, tempString, ans
        solve(n, 0, 0,"", ans);
        return ans;
        
    }
};