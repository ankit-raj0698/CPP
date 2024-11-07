class Solution {
public:
    int dp[101][101];
    int dp1[101][101];
    int cost(int i, int j, string &s){
        if(i >= j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] != s[j])
            return dp[i][j] = 1 + cost(i+1, j-1, s);
        
        return dp[i][j] = cost(i+1, j-1, s);
    }

    int solve(string &s, int ind, int k){

        // when k finished but string isn't finished so this is invalid state
        // because we have to divide string in exactly k partition
        if(k == 0 && ind != -1)
            return 1e9;
        
        // when we have seen all char of string
        if(ind == -1){
            // exactly k partition
            if(k == 0)
                return 0;
            else
                // not k partition so invalid state
                return 1e9;
        }

        if(dp1[ind][k] != -1)
            return dp1[ind][k];

        int ans = 1e9;
        
        // explore by partition at each index 
        for(int x = ind; x >= 0; x--){
            ans = min(ans, solve(s, x-1, k-1) + cost(x, ind, s));
        }
        return dp1[ind][k] = ans;
    }
    int palindromePartition(string s, int k) {
        int n = s.length();
        memset(dp,-1, sizeof(dp));
        memset(dp1, -1, sizeof(dp1));
        return solve(s, n - 1, k);
    }
};