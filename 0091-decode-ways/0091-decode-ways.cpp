class Solution {
public:
    int dp[101];
    int solve(string &s, int ind, int n){
        // base case: we have seen all char
        if(ind == n)
            return 1;
        
        // if curr char is 0 , then no split possible
        if(s[ind] == '0')
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        // consider 1 char
        int one_step = solve(s, ind + 1, n);

        // consider 2 char 
        int two_step = 0;
        if(ind + 1 < n){
            if(s[ind] == '1' || s[ind] == '2' &&  s[ind + 1] <= '6')
                two_step = solve(s, ind + 2, n);
        }
                
        return dp[ind] = one_step + two_step;
    }

    int numDecodings(string s) {
        int n = s.size();

        memset(dp, -1, sizeof(dp));
        return solve(s, 0, n);
    }
};