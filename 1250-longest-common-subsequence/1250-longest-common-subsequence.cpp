class Solution {
public:
    int n, m;
    int dp[1001][1001];
    int solve(string &text1, string &text2, int i, int j){
        if(i >= n || j >= m)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        int op1 = solve(text1, text2, i + 1, j);
        int op2 = solve(text1, text2, i, j + 1);
        int op3 = 0;
        if(text1[i] == text2[j])
            op3 = 1 + solve(text1, text2, i + 1, j + 1);

        return dp[i][j] = max({op1, op2, op3});
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.length();
        m = text2.length();
        memset(dp, -1, sizeof(dp));
        return solve(text1, text2, 0, 0);
        
    }
};